/*
 * Parser.cpp
 *
 *  Created on: 23 Feb 2024
 *      Author: benja
 */

#include "Parser.h"

#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>

#include "Job.h"
#include "Task.h"

Parser::Parser(const std::string &path) :
		path(path) {
}

Parser::Parser(const char *path) {
	this->path = std::string(path);
}

Parser::~Parser() {
	// TODO Auto-generated destructor stub
}

JobShop Parser::parse() {
	std::ifstream File(this->path.c_str());
	// if file is not open exit the program
	if (!File.is_open()) {
		throw(std::runtime_error("Could not open the input file"));
	}

	// parse the first line, which should be the config.
	std::string line;
	getline(File, line);
	std::vector<unsigned char> tokens = parseDigitsInLine(line);
	if (tokens.size() != 2) {
		File.close();
		throw(std::runtime_error("Config invalid, only two digits are allowed."));
	}

	// initialize the jobshop
	JobShop js(tokens[1]);
	unsigned char jobId = 0;

	// parse the rest of the file line by line
	while (getline(File, line)) {
		tokens = parseDigitsInLine(line);
		Job j(jobId);
		// iterate over the tokens in pairs
		for (auto i = tokens.begin(); i != tokens.end(); i += 2) {
			Task t(*i, *(i + 1));
			j.addTask(t);
		}
		// add the newly made job
		js.addJob(j);
		++jobId;
	}
	// close the file
	File.close();
	return js;

}

std::vector<unsigned char> Parser::parseDigitsInLine(const std::string &line) {
	std::vector<unsigned char> tokens;
	/*
	 * This has to be a short because otherwise the >> operator cycles over all the characters instead of the numbers
	 */
	unsigned short value;
	// make a stream out of our input string
	std::istringstream lineStream(line);

	while (lineStream >> value) {
		tokens.push_back(static_cast<unsigned char>(value));
	}
	return tokens;
}
