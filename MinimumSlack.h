/*
 * MinimumSlack.h
 *
 *  Created on: 1 Mar 2024
 *      Author: benja
 */

#ifndef MINIMUMSLACK_H_
#define MINIMUMSLACK_H_

#include <map>
#include <memory>
#include "JobShop.h"

class MinimumSlack {
public:
	MinimumSlack(const std::shared_ptr<JobShop>& js);
	virtual ~MinimumSlack();

	void calculateSlacks();

	void schedule();

private:
	std::shared_ptr<JobShop> jobshop;
	std::map<unsigned char, unsigned short> slacks;
	std::map<unsigned char, unsigned char> taskProgress;
	void addToEarliestStarts(unsigned char time);
};

#endif /* MINIMUMSLACK_H_ */
