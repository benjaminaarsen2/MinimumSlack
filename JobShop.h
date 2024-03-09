/*
 * JobShop.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <iostream>
#include <map>
#include <vector>

#include "Job.h"
#include "Machine.h"

class JobShop {
public:
	explicit JobShop(unsigned char nMachines);
	virtual ~JobShop();

	Job& addJob(const Job &job);
//	std::vector<Job>& getJobs();
	void schedule();
	friend std::ostream& operator<<(std::ostream &os, const JobShop &rhs);
private:
	unsigned char nMachines;
	std::map<unsigned char, Machine> machines;
	void calculateSlacks();
	std::vector<Job>::iterator getNextJob();
	bool allJobsDone();
	bool machineAvailable(unsigned char machineNum, unsigned short time);
	unsigned short getEarliestAvailablility();
	std::vector<Job> jobs;
};

#endif /* JOBSHOP_H_ */
