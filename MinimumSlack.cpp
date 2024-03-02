/*
 * MinimumSlack.cpp
 *
 *  Created on: 1 Mar 2024
 *      Author: benja
 */

#include <algorithm>
#include "MinimumSlack.h"
#include "Job.h"
#include "JobResult.h"

MinimumSlack::MinimumSlack(const std::shared_ptr<JobShop> &js) :
		jobshop(js) {
	for (unsigned char i = 0; i < jobshop->nJobs; ++i) {
		taskProgress.insert(std::make_pair(i, 0));
	}
}

MinimumSlack::~MinimumSlack() {
	// TODO Auto-generated destructor stub
}



void MinimumSlack::calculateSlacks() {

	const auto max = std::max_element(jobshop->getJobs().begin(),
			jobshop->getJobs().end(), [](const Job &a, const Job &b) {
				return a.getDuration() < b.getDuration();
			});

	unsigned char index = 0;

	for (auto &job : jobshop->getJobs()) {
		const unsigned short slack = (*max).getDuration() - job.getDuration();
		slacks.insert_or_assign(++index, slack);
	}
}

void MinimumSlack::schedule() {
	calculateSlacks(); //make sure the initial slack values are set
	unsigned short time = 0;

	while (true) {
		const auto minJob = std::min_element(slacks.begin(), slacks.end(),
				[](const std::pair<unsigned char, unsigned short> &a,
						const std::pair<unsigned char, unsigned short> &b) {
					return a.second < b.second;
				});
		const auto job = (*minJob).first;
		const auto taskNum = taskProgress.at(job);
		const auto& task = jobshop->getJobs().at(job).getTasks().at(taskNum);
		const auto taskDuration = task.getDuration();
		if (time < task.getEarliestStart()) {
			time = task.getEarliestStart();
		}
		time += taskDuration;
		jobshop->addToAllEarliestStarts(taskDuration);


	}

}

void MinimumSlack::addToEarliestStarts(unsigned char time) {
	for (const auto& [jobNum, task] : task)
}
