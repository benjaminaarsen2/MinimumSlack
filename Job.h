/*
 * Job.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef JOB_H_
#define JOB_H_

#include <iostream>
#include <vector>

#include "Task.h"

class Job {
public:
	explicit Job(unsigned char id);
	virtual ~Job();

	bool isDone() const;
	void setDone();
	bool addTask(Task &task);
	unsigned short getDuration() const;
	std::vector<Task>& getTasks();
	friend std::ostream& operator<<(std::ostream &os, const Job &rhs);
	bool operator==(const Job &rhs) const;
	bool operator!=(const Job &rhs) const;
	friend bool operator<(const Job &lhs, const Job &rhs);
	void setSlack(unsigned short slack);
	unsigned short getSlack() const;
	unsigned char getId() const;
	void addToEarliestStarts(unsigned short time);
	void setStartTime(unsigned short time);
	unsigned short getStartTime() const;
	std::vector<Task>::iterator getNextTask();
private:
	std::vector<Task> tasks;
	unsigned char id;
	unsigned short slack;
	bool done;
	unsigned short startTime;
	void calculateEarliestStarts();

};

#endif /* JOB_H_ */
