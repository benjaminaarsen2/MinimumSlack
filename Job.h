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
	Job(unsigned char id);
	virtual ~Job();

	bool addTask(Task& task);
	unsigned short getDuration() const;
	std::vector<Task>& getTasks();
	friend std::ostream& operator<< (std::ostream& os, const Job& rhs);
	void setSlack(unsigned short slack);
	unsigned short getSlack() const;
	void addToEarliestStarts(unsigned char time);
	Task& getNextTask();
private:
	std::vector<Task> tasks;
	unsigned char id;
	unsigned short slack;
	bool isDone;
	unsigned short endTime;
	void calculateEarliestStarts();




};

#endif /* JOB_H_ */
