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
	unsigned short getDuration() const;
	unsigned short calcEarliestStart(unsigned char idx);
	std::vector<Task>& getTasks();
	friend std::ostream& operator<< (std::ostream& os, const Job& rhs);
private:

	std::vector<Task> tasks;
};

#endif /* JOB_H_ */
