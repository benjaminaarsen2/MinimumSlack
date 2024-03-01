/*
 * MinimumSlack.cpp
 *
 *  Created on: 1 Mar 2024
 *      Author: benja
 */

#include <algorithm>
#include "MinimumSlack.h"

MinimumSlack::MinimumSlack(Jobshop& js) : jobshop(js){
	// TODO Auto-generated constructor stub

}

MinimumSlack::~MinimumSlack() {
	// TODO Auto-generated destructor stub
}

void MinimumSlack::calculateSlack() {
	auto& jobs = jobshop.getJobs();

	const auto max = std::max_element(jobs.begin(), jobs.end(), [](const Job& a, const Job&b) {
		return a.getDuration() < b.getDuration();
	});

	for (auto& job : jobs) {
		job.setSlack((*max).getDuration() - job.getDuration());
	}

}
