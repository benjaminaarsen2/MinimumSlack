/*
 * Parser.cpp
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#include "Parser.h"
#include <fstream>
#include <iostream>
#include <regex>

Parser::Parser(std::string path) :
		path(path) {
}

Parser::Parser(char *path) {
	this->path = std::string(path);
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

JobShop Parser::parse() {
	std::ifstream File(this->path.c_str());

	if (File.is_open()) {
		std::string line;
		getline(File, line);
		std::vector<unsigned char> tokens = parseDigitsInLine(line);

		if (tokens.size() != 2) {
			throw(std::runtime_error(
					"Config invalid, only two digits are allowed."));
		}

		JobShop js(tokens[0], tokens[1]);

		while (getline(File, line)) {
			tokens = parseDigitsInLine(line);
			Job j;
			for (auto i = tokens.begin(); i != tokens.end(); ++i) {
				Task t(*i, *(i + 1));
				j.addTask(t);
				++i;
			}
			js.addJob(j);
		}

		return js;

	} else {
		std::cout << "file not open" << std::endl;
		return JobShop(0, 0);
	}

}

std::vector<unsigned char> Parser::parseDigitsInLine(const std::string &line) {
	std::vector<unsigned char> tokens;
	std::string tok;
	std::size_t start, end;
	start = end = 0;

	while ((start = line.find_first_not_of(' ', end)) != std::string::npos) {
		end = line.find(' ', start);

		if (end == std::string::npos) {
			end = line.length();
		}

		tokens.push_back(stoi(line.substr(start, end - start)));
	}
	return tokens;
}
