/*
 * JobResult.h
 *
 *  Created on: 2 Mar 2024
 *      Author: benja
 */

#ifndef JOBRESULT_H_
#define JOBRESULT_H_

#include <iostream>

class JobResult {
public:
	JobResult(unsigned char _id, unsigned short st);
	virtual ~JobResult();

	void setEndTime(unsigned short endTime);
	friend std::ostream& operator<<(std::ostream& os, const JobResult& rhs);
		private:
			unsigned char id;
			unsigned short startTime;
			unsigned short endTime;
		};

#endif /* JOBRESULT_H_ */

