#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Stack.hpp"
#include <string>
#include <vector>

class Tokenizer{
	public:
		Tokenizer(){
			branches.push_back("beginning");
		}
		void parse(std::string fileName);
		void printLoopDepth();
		void printKeywords();
		void printIdentifiers();
		void printConstants();
		void printDelimiters();
		void printErrors();
	private:
		Stack beginStack;
		Stack parStack;
		Stack loopStack;
		
		std::vector<std::string> branches;		//Running list of found branches
		std::vector<std::string> keywords;		//List of found keywords
		std::vector<std::string> constants;		//List of found constants
		std::vector<char> delimiters;			//List of found delimiters
		std::vector<std::string> identifiers;	//List of found identifiers
		std::vector<std::string> errors;		//List of found errors
		
		void findKeywords(std::string str);
		bool isKeyword(std::string word);
		
		void findConstants(std::string str);
		bool isConstFound(std::string constant);
		
		void findDelimiters(std::string str);
		bool isDelimiter(char c);
		
		void findIdentifiers(std::string str);
		bool isIdentifierFound(std::string id);
};

#endif
