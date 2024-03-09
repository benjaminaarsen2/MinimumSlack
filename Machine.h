/*
 * Machine.h
 *
 *  Created on: 4 Mar 2024
 *      Author: benja
 */

#ifndef MACHINE_H_
#define MACHINE_H_

#include <iostream>
#include <memory>

#include "Task.h"

class Machine {
public:
	Machine(Task &task);
	Machine(const Machine &rhs);
	virtual ~Machine();
	bool isActive(unsigned short time) const;
	unsigned short getDoneTime() const;
	void setTask(const Task &task);
	const Task& getTask() const;
	Machine& operator=(const Machine &rhs);
	friend std::ostream& operator<<(std::ostream &os, const Machine &rhs);

private:
	// when i make this a reference everything breaks so i won't do that :)
	std::shared_ptr<Task> task;

};

#endif /* MACHINE_H_ */
