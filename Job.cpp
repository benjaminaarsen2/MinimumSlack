/*
 * Job.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "Job.h"

#include <algorithm>

Job::Job(unsigned char cid) :
		id(cid), slack(-1), done(false), startTime(-1) {

}

Job::~Job() {
	// TODO Auto-generated destructor stub
}

bool Job::addTask(Task &task) {
	// add a new task and recalculate earliest starts
	tasks.push_back(task);
	calculateEarliestStarts();
	return true;
}

unsigned short Job::getDuration() const {
	const auto &lastTask = tasks.back();
	return lastTask.getDuration() + lastTask.getEarliestStart();
}

std::vector<Task>& Job::getTasks() {
	return this->tasks;
}

std::ostream& operator<<(std::ostream &os, const Job &rhs) {
	os << "Job: " << (int) rhs.id << " [";
	for (const auto &task : rhs.tasks) {
		os << (int) task.getMachine() << ": [" << (int) task.getDuration()
				<< " " << (int) task.getEarliestStart() << "], ";
	}
	os << "]" << " Duration: " << (int) rhs.getDuration() << " Slack: "
			<< (int) rhs.getSlack() << (rhs.done ? " Done" : "");
	return os;
}

bool operator<(const Job &lhs, const Job &rhs) {
	if (lhs.slack == rhs.slack) {
		return lhs.id < rhs.id;
	}
	return lhs.slack < rhs.slack;
}

void Job::setSlack(unsigned short s) {
	slack = s;
}

void Job::addToEarliestStarts(unsigned short time) {
	for (auto &task : tasks) {
		if (!task.isStarted()) {
			task.setEarliestStart(task.getEarliestStart() + time);
		}
	}
}

unsigned short Job::getSlack() const {
	return slack;
}
/*
 * Return an iterator to the first task that has not been started yet
 */
std::vector<Task>::iterator Job::getNextTask() {
	const auto checkStarted = [](const Task &task) {
		return task.isStarted();
	};
	const auto it = std::find_if_not(tasks.begin(), tasks.end(), checkStarted);

	return it;
}

unsigned char Job::getId() const {
	return this->id;
}

void Job::setStartTime(unsigned short time) {
	this->startTime = time;
}

unsigned short Job::getStartTime() const {
	return this->startTime;
}
void Job::calculateEarliestStarts() {
	unsigned short es = 0;
	for (auto &task : tasks) {
		task.setEarliestStart(es);
		es += task.getDuration();
	}
}

bool Job::isDone() const {
	return this->done;
}

void Job::setDone() {
	this->done = true;
}

bool Job::operator ==(const Job &rhs) const {
	if (this == &rhs) {
		return true;
	}
	return this->done == rhs.done && this->startTime == rhs.startTime
			&& this->id == rhs.id && this->slack == rhs.slack
			&& this->tasks == rhs.tasks;
}

bool Job::operator !=(const Job &rhs) const {
	return !(*this == rhs);
}
