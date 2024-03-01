/*
 * main.cpp
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#include "Parser.h"

int main(int argc, char **argv) {
	if (!argv[1]) {
		std::cout << "No file input provided" << std::endl;
		return 0;
	}
	Parser parser(argv[1]);
	JobShop js = parser.parse();
	std::cout << js << std::endl;
}



