/*
 * Job.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef JOB_H_
#define JOB_H_

#include <map>
#include <vector>
#include <iostream>
#include "Task.h"

class Job {
public:
	Job();
	virtual ~Job();

	bool addTask(Task& task);
	friend std::ostream& operator<< (std::ostream& os, const Job& rhs);
private:
	unsigned short calcEarliestStart(unsigned char idx);
	std::map<unsigned char, unsigned char> jobDescription;
	std::vector<Task> tasks;
};

#endif /* JOB_H_ */
