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

Job::Job() : slack(0){
	// TODO Auto-generated constructor stub

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

bool Job::addTask(Task& task) {
	task.setEarliestStart(calcEarliestStart(tasks.size()));
	tasks.push_back(task);

	return true;
}

unsigned short Job::calcEarliestStart(unsigned char idx) {
	unsigned short res;
	for (std::size_t i = 0; i < tasks.size(); ++i) {
		res += tasks.at(i).getDuration();
	}
	return res;
}

unsigned short Job::getDuration() const{
	const auto& lastTask = tasks.back();
	return lastTask.getDuration() + lastTask.getEarliestStart();
}

std::ostream& operator<< (std::ostream& os, const Job& rhs) {
	os <<  "[";
//	for (const auto& [machine, taskTime] : rhs.jobDescription) {
//		os << (int)machine << ": " << (int)taskTime << ", ";
//	}
	for (const auto& task : rhs.tasks) {
		os << (int)task.getMachine() << ": [" << (int)task.getDuration() << " " << (int)task.getEarliestStart() << "], ";
	}
	os << "]" << " Duration: " << (int)rhs.getDuration() << std::endl;
	return os;
}
