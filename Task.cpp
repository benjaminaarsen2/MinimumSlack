/*
 * Task.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "Task.h"

Task::Task(unsigned char machine, unsigned char time) : earliestStart(0), started(false), machine(machine), duration(time)  {
	// TODO Auto-generated constructor stub
}

Task::~Task() {
	// TODO Auto-generated destructor stub
}

unsigned char Task::getMachine() const {
	return this->machine;
}

unsigned char Task::getDuration() const {
	return this->duration;
}

unsigned char Task::setEarliestStart(unsigned char es) {
	this->earliestStart = es;
	return this->earliestStart;
}

unsigned char Task::getEarliestStart() const {
	return this->earliestStart;
}

bool Task::isStarted() {
	return started;
}

Task& Task::operator =(const Task &rhs) {
	if (this != &rhs) {
		this->duration = rhs.duration;
		this->earliestStart = rhs.earliestStart;
		this->machine = rhs.machine;
		this->started = rhs.started;
	}
	return *this;
}

void Task::start() {
	started = true;
}

std::ostream& operator<< (std::ostream& os, const Task& rhs) {
	return os << (int)rhs.machine << " " << (int)rhs.duration << " " << (int)rhs.earliestStart;
}
