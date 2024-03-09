/*
 * main.cpp
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#include <iostream>

#include "JobShop.h"
#include "Parser.h"

//#include "MinimumSlack.h"

int main(int argc, char **argv) {
	if (argc < 2) {
		std::cout << "No file input provided" << std::endl;
		return 0;
	}
	Parser parser(argv[1]);
	JobShop js = parser.parse();
	js.schedule();
//	MinimumSlack ms(std::make_shared<JobShop>(js));
//	ms.schedule();
}

