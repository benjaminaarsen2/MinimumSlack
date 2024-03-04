/*
 * Machine.cpp
 *
 *  Created on: 4 Mar 2024
 *      Author: benja
 */

#include "Machine.h"

Machine::Machine(Task &task) :
		task(task), active(false) {
}
Machine::Machine(const Machine &rhs) : task(rhs.task), active(rhs.active) {
}

Machine::~Machine() {
	// TODO Auto-generated destructor stub
}

bool Machine::isActive() {
	return active;
}

void Machine::setActive(bool active) {
	this->active = active;
}

void Machine::setTask(const Task &task) {
	this->task = task;
}

const Task& Machine::getTask() {
	return this->task;
}


Machine& Machine::operator= (const Machine& rhs) {
	if (this != &rhs) {
		this->active = rhs.active;
		this->task = rhs.task;
	}
	return *this;
}
//unsigned char Machine::getId() const {
//	return id;
//}
