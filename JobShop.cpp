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

std::ostream& operator<<(std::ostream &os, const JobShop &rhs) {
	os << "Jobs: " << (int) rhs.nJobs << " Machines: " << (int) rhs.nMachines
			<< std::endl;

	for (const auto &job : rhs.jobs) {
		os << job << std::endl;
	}
	return os;
}
