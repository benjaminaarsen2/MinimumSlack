/*
 * Task.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef TASK_H_
#define TASK_H_

class Task {
public:
	Task(unsigned char machine, unsigned char time);
	virtual ~Task();

	unsigned char getMachine() const;
	unsigned char getDuration() const;
	unsigned char getEarliestStart() const;

	unsigned char setEarliestStart(unsigned char es);

private:
	unsigned char machine;
	unsigned char duration;
	unsigned char earliestStart;
};

#endif /* TASK_H_ */
