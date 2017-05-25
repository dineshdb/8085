#include "parser.hh"

using namespace std;

std::vector<string> split(string &s, string delim){
	std::vector<string> res;

	for(size_t i=0, startindex=0; i < s.length(); i++){
		if( delim.find(s[i]) != string::npos){
			string a = s.substr(startindex, i);
			startindex = ++i;
			res.push_back(a);
		}
	}
	return res;
}

Parser::Parser(string f){
	file = f;
	// TODO: Add all keys into the map.
	mnemonic["add"] = ADD;
	mnemonic["adc"] = ADC;
}

void Parser::setFile(string f){
	file = f;
}

void Parser::parse(){
	ifstream pf(file, ifstream::in);
	std::string temp;

	while(getline(pf, temp)){
		temp = ltrim(temp);
		if(temp.length() == 0){
			continue;
		}
		parseLine(temp);
	}

}

void Parser::parseLine(string &line){
	string mnemonic, source, dest;
	size_t i;
	if((i =line.find(" ")) != string::npos){	// mnemonic found
		mnemonic = line.substr(0, i);
		line = line.substr(++i, line.length());
		if((i = line.find(",")) != string::npos){
			source = line.substr(0, i);
			dest = line.substr(i+1, line.length());
			source = trim(source);
			dest = trim(dest);
		} else {
			// TODO: Is it invalid line
			source = trim(line);
		}
	} else { // Single instruction or bad line
		// TODO: Is it invalid line
		mnemonic = trim(line);
	}

}

string &Parser::trim(string &s){
	s = ltrim(s);
	s = rtrim(s);
	return s;
}
string &Parser::ltrim(string &s){
	if(s.length() ==0){
		return s;
	}
	int begin = 0;
	while(s[begin++] == ' ');
	s = s.substr(begin - 1, s.length());
	return s;
}


string &Parser::rtrim(string& s){
	if(s.length()==0){
		return s;
	}
	int end=s.length()-1;
	while(s[end--]== ' ');
	s=  s.substr(0, end+2);
	return s;
}
