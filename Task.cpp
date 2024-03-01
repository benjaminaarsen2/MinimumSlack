/*
 * Task.cpp
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#include "Task.h"

Task::Task(unsigned char machine, unsigned char time) : machine(machine), duration(time), earliestStart(0) {
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
