/*
 * Task.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef TASK_H_
#define TASK_H_

#include <iostream>

class Task {
public:
	Task(unsigned char machine, unsigned char time);
	Task(const Task& rhs);
	virtual ~Task();
	unsigned char getMachine() const;
	unsigned char getDuration() const;
	unsigned short getEarliestStart() const;

	unsigned short setEarliestStart(unsigned short es);
	friend std::ostream& operator<<(std::ostream &os, const Task &rhs);
	bool operator==(const Task &rhs) const;
	Task& operator= (const Task& rhs);
	bool isStarted() const;
	void start();
private:
	unsigned short earliestStart;
	bool started;
	unsigned char machine;
	unsigned char duration;
};

#endif /* TASK_H_ */
