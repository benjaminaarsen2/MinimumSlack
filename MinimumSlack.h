/*
 * MinimumSlack.h
 *
 *  Created on: 1 Mar 2024
 *      Author: benja
 */

#ifndef MINIMUMSLACK_H_
#define MINIMUMSLACK_H_

#include <map>
#include "JobShop.h"

class MinimumSlack {
public:
	MinimumSlack(JobShop& js);
	virtual ~MinimumSlack();

	void calculateSlack();

private:
	JobShop& jobshop;
	std::map<unsigned char, JobShop&>
};

#endif /* MINIMUMSLACK_H_ */
