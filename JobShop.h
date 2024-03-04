/*
 * JobShop.h
 *
 *  Created on: 19 Feb 2024
 *      Author: benja
 */

#ifndef JOBSHOP_H_
#define JOBSHOP_H_

#include <vector>
#include <map>
#include "Job.h"
#include "Machine.h"

class JobShop {
public:
	JobShop();
	virtual ~JobShop();

	Job& addJob(const Job& job);
	std::vector<Job>& getJobs();
	void schedule();
	friend std::ostream& operator<< (std::ostream& os, const JobShop& rhs);
private:
	std::map<unsigned char, Machine> machines;
	void calculateSlacks();
	Job& getLeastSlack();

	std::vector<Job> jobs;
};

#endif /* JOBSHOP_H_ */
