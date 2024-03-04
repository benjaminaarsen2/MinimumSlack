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

Job::Job(unsigned char cid): id(cid){

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

bool Job::addTask(Task& task) {
	tasks.push_back(task);
	calculateEarliestStarts();
	return true;
}

unsigned short Job::getDuration() const{
	const auto& lastTask = tasks.back();
	return lastTask.getDuration() + lastTask.getEarliestStart();
}

std::vector<Task>& Job::getTasks(){
	return this->tasks;
}


std::ostream& operator<< (std::ostream& os, const Job& rhs) {
	os <<  "[";
//	for (const auto& [machine, taskTime] : rhs.jobDescription) {
//		os << (int)machine << ": " << (int)taskTime << ", ";
//	}
	for (const auto& task : rhs.tasks) {
		os << (int)task.getMachine() << ": [" << (int)task.getDuration() << " " << (int)task.getEarliestStart() << "], ";
	}
	os << "]" << " Duration: " << (int)rhs.getDuration();
	return os;
}

bool operator< (const Job& lhs, const Job& rhs) {
	return lhs.slack < rhs.slack;
}

void Job::setSlack(unsigned short s) {
	slack = s;
}

void Job::addToEarliestStarts(unsigned char time) {
	for(auto& task : tasks) {
		if (!task.isStarted()) {
			task.setEarliestStart(task.getEarliestStart() + time);
		}
	}
}

unsigned short Job::getSlack() const{
	return slack;
}

Task& Job::getNextTask() {
	for(auto& task : tasks) {
		if (!task.isStarted()) {
			return task;
		}
	}
	std::cout << "No new task available" << std::endl;
	return tasks.at(0);
}

void Job::calculateEarliestStarts() {
	unsigned char es = 0;
	for(auto& task : tasks) {
			task.setEarliestStart(es);
			es += task.getDuration();
		}
}


