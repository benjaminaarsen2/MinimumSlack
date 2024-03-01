/*
 * main.cpp
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#include "Parser.h"

int main(int argc, char **argv) {
	Parser parser(argv[1]);
	JobShop js = parser.parse();
	std::cout << js << std::endl;
}



