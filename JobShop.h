/*
 * JobShop.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <string>
#include <vector>
#include "Job.h"

class JobShop {
public:
	JobShop(const unsigned char nJobs, const unsigned char nMachines);
	virtual ~JobShop();

	Job& addJob(const Job& job);
	std::vector<Job>& getJobs();
	void schedule();
	friend std::ostream& operator<< (std::ostream& os, const JobShop& rhs);
private:
	void calculateSlacks();
	Job& getLeastSlack();
	std::vector<Job> jobs;
	unsigned char nJobs;
	unsigned char nMachines;
};

#endif /* JOBSHOP_H_ */
