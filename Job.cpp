/*
 * Job.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "Job.h"
#include <utility>
#include <iostream>
#include <algorithm>

Job::Job() {
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

bool Job::addTask(Task& task) {
//	const auto [it, success] = this->jobDescription.insert({task.getMachine(), task.getTime()});
	task.setEarliestStart(calcEarliestStart(tasks.size()));
	tasks.push_back(task);
//	std::cout << "machine " << (int)task.getMachine() << " time " << (int)task.getTime() << std::endl;
//	return success;
	return true;
}

unsigned short Job::calcEarliestStart(unsigned char idx) {
	unsigned short res;
	for (std::size_t i = 0; i < tasks.size(); ++i) {
		res += tasks.at(i).getTime();
	}
	return res;
}

std::ostream& operator<< (std::ostream& os, const Job& rhs) {
	os <<  "[";
//	for (const auto& [machine, taskTime] : rhs.jobDescription) {
//		os << (int)machine << ": " << (int)taskTime << ", ";
//	}
	for (const auto& task : rhs.tasks) {
		os << (int)task.getMachine() << ": [" << (int)task.getTime() << " " << (int)task.getEarliestStart() << "], ";
	}
	os << "]";
	return os;
}
