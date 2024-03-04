/*
 * Machine.h
 *
 *  Created on: 4 Mar 2024
 *      Author: benja
 */

#ifndef MACHINE_H_
#define MACHINE_H_
#include "Task.h"

class Machine {
public:
	Machine( Task& task);
	Machine(const Machine& rhs);
	virtual ~Machine();
	bool isActive();
	void setActive(bool active);
	void setTask(const Task& task);
	const Task& getTask();
	Machine& operator= (const Machine& rhs);
//	unsigned char getId() const;

private:
	Task& task;
	bool active;

};

#endif /* MACHINE_H_ */
