/*
 * JobShop.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "JobShop.h"

#include <algorithm>
#include <iterator>
#include <utility>
#include <sstream>

#include "Task.h"

JobShop::JobShop(unsigned char nMachines) :
		nMachines(nMachines) {
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

Job& JobShop::addJob(const Job &job) {
	this->jobs.push_back(job);
	return this->jobs.back();
}

//std::vector<Job>& JobShop::getJobs() {
//	return this->jobs;
//}

std::ostream& operator<<(std::ostream &os, const JobShop &rhs) {
	os << "Jobs: " << (int) rhs.jobs.size() << " Machines: "
			<< (int) rhs.machines.size() << std::endl;

	for (const auto &job : rhs.jobs) {
		os << job << std::endl;
	}
	return os;
}

/*
 * Main scheduling function using the Least Slack algorithm
 */
void JobShop::schedule() {
	unsigned short earliestAvailable = 0;
	// continue iterating until we know that all jobs are done
	while (!allJobsDone()) {
		calculateSlacks();
		for (auto &job : jobs) {
			// go to the next job if current job is done.
			if (job.isDone())
				continue;

			// retrieve the next possible task for the job
			auto &task = *job.getNextTask();

			/*
			 * Check if the parsed machine is valid, this cannot really be done in the parser since it just spits out values
			 * and does not really validate apart from the config token length.
			 */
			if (task.getMachine() >= nMachines) {
				std::ostringstream error_msg;
				error_msg << "Machine for task " << task << " at job "
						<< job.getId() << "is outside of given machine config";
				throw std::runtime_error(error_msg.str());
			}

			// if we cannot start this task yet
			if (task.getEarliestStart() > earliestAvailable) {
				continue;
			}

			/*
			 * If the machine for this task is currently busy add the time we have to wait
			 * to ES and go to the next job
			 */
			if (!machineAvailable(task.getMachine(), task.getEarliestStart())) {
				// time that machine will be free
				const auto machineOccupiedUntil =
						machines.at(task.getMachine()).getDoneTime();

				// add the time that we have to wait for the machine to ES
				job.addToEarliestStarts(
						machineOccupiedUntil - task.getEarliestStart());
				continue;
			}

			// set the start time for the job when this is the first task within the job.
			if (task == job.getTasks().front()) {
				job.setStartTime(task.getEarliestStart());
			}

			/*
			 * If the machine needed doesn't exist yet, create it
			 * Otherwise update the task for the machine.
			 */
			if (machines.find(task.getMachine()) == machines.end()) {
				machines.insert( { task.getMachine(), Machine(task) });
			} else {
				machines.at(task.getMachine()).setTask(task);
			}

			// set the start flag so the task won't be selected next time.
			task.start();

			// if this was the last task our job is done.
			if (task == job.getTasks().back()) {
				job.setDone();
			}

		}
		earliestAvailable = getEarliestAvailablility();
	}
	std::sort(jobs.begin(), jobs.end(), [](const Job &a, const Job &b) {
		return a.getId() < b.getId();
	});
	for (const auto &job : jobs) {
		std::cout << (int) job.getId() << " " << job.getStartTime() << " "
				<< job.getDuration() << std::endl;
		;
	}
}

void JobShop::calculateSlacks() {
	const auto &maxDurationJob = *std::max_element(jobs.begin(), jobs.end(),
			[](const Job &a, const Job &b) {
				return a.getDuration() < b.getDuration();
			});
	for (auto &job : jobs) {
		job.setSlack(maxDurationJob.getDuration() - job.getDuration());
	}
	std::sort(jobs.begin(), jobs.end());
}

bool JobShop::allJobsDone() {

	const auto checkDone = [](const Job &job) {
		return job.isDone();
	};

	const auto allDone = std::all_of(jobs.begin(), jobs.end(), checkDone);

	return allDone;
}

// retrieves the next job that is not done yet
std::vector<Job>::iterator JobShop::getNextJob() {
	const auto checkJobDone = [](const Job &job) {
		return job.isDone();
	};
	const auto it = std::find_if_not(jobs.begin(), jobs.end(), checkJobDone);
	return it;
}

bool JobShop::machineAvailable(unsigned char machineNum, unsigned short time) {
	const auto res = machines.find(machineNum);
	if (res == machines.end()) {
		return true;
	}
	return !(*res).second.isActive(time);
}

// retrieves the machine with the tasks that ends earliest
unsigned short JobShop::getEarliestAvailablility() {
	if (machines.size() == 0) {
		return 0;
	}
	const auto &m = *std::min_element(machines.begin(), machines.end(),
			[](const std::pair<unsigned char, Machine> &a,
					const std::pair<unsigned char, Machine> &b) {
				return a.second.getDoneTime() < b.second.getDoneTime();
			});

	auto doneTime = m.second.getDoneTime();
	machines.erase(m.first);
	return doneTime;
}
