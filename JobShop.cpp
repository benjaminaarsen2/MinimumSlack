/*
 * JobShop.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "JobShop.h"
#include <iostream>
#include <algorithm>

JobShop::JobShop(const unsigned char nJobs, const unsigned char nMachines) :
		nJobs(nJobs), nMachines(nMachines) {
	// TODO Auto-generated constructor stub

}

JobShop::~JobShop() {
	// TODO Auto-generated destructor stub
}

Job& JobShop::addJob(const Job &job) {
	this->jobs.push_back(job);
	return this->jobs.back();
}


std::vector<Job>& JobShop::getJobs() {
	return this->jobs;
}

std::ostream& operator<<(std::ostream &os, const JobShop &rhs) {
	os << "Jobs: " << (int) rhs.nJobs << " Machines: " << (int) rhs.nMachines
			<< std::endl;

	for (const auto &job : rhs.jobs) {
		os << job << std::endl;
	}
	return os;
}

void JobShop::schedule() {
	while (true) {
		std::sort(jobs.begin(), jobs.end());
		auto& ls = getLeastSlack();
		auto& task = ls.getNextTask();

	}
}

void JobShop::calculateSlacks() {
	const auto& maxDurationJob = *std::max_element(jobs.begin(),
				jobs.end(), [](const Job &a, const Job &b) {
					return a.getDuration() < b.getDuration();
				});
	for (auto& job : jobs) {
		job.setSlack(maxDurationJob.getDuration() - job.getDuration());
	}
}

Job& JobShop::getLeastSlack() {
	auto& ls = *std::min_element(jobs.begin(), jobs.end(), [](const Job& a, const Job &b) {
		return a.getSlack() < b.getSlack();
	});
	return ls;
}
