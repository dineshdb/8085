#ifndef PARSER_HH
#define PARSER_HH

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <functional>

#include "typedef.hh"


class Parser {
std::string file;
std::map<std::string, std::function<void(std::vector<i8> &, std::string &, std::string &)>> pm;

static void parseAdd(std::vector<i8> &res, std::string &d, std::string &s){
	if(isRegisterLocation(d)){
		if(isRegisterLocation(s)){

		} else {

		}
	} else {
		if(isRegisterLocation(s)){

		} else {

		}
	}
}

static bool isRegisterLocation(std::string &s){
	static std::string regs = "abcdehl";
	if(s.length() == 1 && regs.find(s) != std::string::npos){
		return true;
	}
	return false;
}

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
