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
	virtual ~Task();

	unsigned char getMachine() const;
	unsigned char getDuration() const;
	unsigned char getEarliestStart() const;

	unsigned char setEarliestStart(unsigned char es);
	friend std::ostream& operator<< (std::ostream& os, const Task& rhs);
	Task& operator= (const Task& rhs);
	bool isStarted();
	void start();
private:
	unsigned char earliestStart;
	bool started;
	unsigned char machine;
	unsigned char duration;
};

#endif /* TASK_H_ */
