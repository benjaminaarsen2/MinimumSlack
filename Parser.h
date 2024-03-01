/*
 * Parser.h
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#ifndef PARSER_H_
#define PARSER_H_

#include <filesystem>
#include <vector>
#include "JobShop.h"

class Parser {
public:
	Parser(std::string path);
	Parser(char* path);
	virtual ~Parser();

	JobShop parse();
	static std::vector<unsigned char> parseDigitsInLine(const std::string &line);
private:
	std::filesystem::path path;
};

#endif /* PARSER_H_ */
