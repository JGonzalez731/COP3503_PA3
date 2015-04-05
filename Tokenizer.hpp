#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Stack.hpp"
#include <string>
#include <vector>

class Tokenizer{
	public:
		Tokenizer(){};
		void parse(std::string fileName);
		void printKeywords();
		void printConstants();
		void printErrors();
	private:
		Stack keyStack;
		std::vector<std::string> keywords;		//List of found keywords
		std::vector<std::string> constants;		//List of found constants
		std::vector<std::string> errors;		//List of found errors
		void findKeywords(std::string str);
		bool isKeyword(std::string word);
		void findConstants(std::string str);
		bool isConstFound(std::string constant);
};

#endif
