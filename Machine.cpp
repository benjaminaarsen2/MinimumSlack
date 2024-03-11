/*
 * Machine.cpp
 *
 *  Created on: 4 Mar 2024
 *      Author: benja
 */

#include "Machine.h"

#include <iostream>

Machine::Machine(Task &task) :
		task(std::make_shared<Task>(task)) {
//	std::cout << "machine constructor" << std::endl;
}

Machine::Machine(const Machine &rhs) :
		task(rhs.task) {
}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}

void Machine::setTask(const Task &task) {
	this->task = std::make_shared<Task>(task);
}

const Task& Machine::getTask() const {
	return *(this->task);
}

// determine if the machine is active at a certain time
bool Machine::isActive(unsigned short time) const {
	return getDoneTime() > time;
}

unsigned short Machine::getDoneTime() const {
	return (*task).getEarliestStart() + (*task).getDuration();
}

Machine& Machine::operator=(const Machine &rhs) {
	if (this != &rhs) {
		this->task = rhs.task;
	}
	return *this;
}

std::ostream& operator<<(std::ostream &os, const Machine &rhs) {
	return os << rhs.getTask();
}
