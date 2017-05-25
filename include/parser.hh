#ifndef PARSER_HH
#define PARSER_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

#include "microprocessor.hh"

class Parser {
std::string file;
std::map<std::string, MNEMONIC> mnemonic;

public:
	Parser(std::string f);
	void setFile(std::string f);
	void parse();
	std::string &trim(std::string& s);
	std::string &rtrim(std::string& s);
	std::string &ltrim(std::string& s);
	void parseLine(std::string &line);

};
#endif
