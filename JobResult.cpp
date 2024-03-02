/*
 * JobResult.cpp
 *
 *  Created on: 2 Mar 2024
 *      Author: benja
 */

#include "JobResult.h"

JobResult::JobResult(unsigned char _id, unsigned short st) : id(_id), startTime(st), endTime(-1) {
}

JobResult::~JobResult() {
	// TODO Auto-generated destructor stub
}

void JobResult::setEndTime(unsigned short endTime) {
	this->endTime = endTime;
}

std::ostream& operator<<(std::ostream& os, const JobResult& rhs) {
	return os << rhs.id << " " << rhs.startTime << " " << rhs.endTime << std::endl;
}
