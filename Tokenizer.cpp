#include <fstream>
#include "TOKEN_CONSTANTS.hpp"
#include <ctype.h>
#include "Tokenizer.hpp"
#include <string>
#include <iostream>

using namespace std;

void Tokenizer::parse(string fileName){
	//Open file
	ifstream fileStream(fileName.c_str());
	
	//Check if file opened successfully
	if(!fileStream.is_open()){
		//TODO throw an error
		cout << "Unable to open file." << endl;
		
		return;
	}
	
	/* Tokenize file line by line */
	string line;
	
	while(getline(fileStream, line)){
		//Look for possible keywords
		findKeywords(line);
		
		//Look for possible constants
		findConstants(line);
		
		//TODO look for more things!
	}
}

//Prints a list of used keywords, in the order that they first appeared
void Tokenizer::printKeywords(){
	vector<string>::iterator it;
	
	cout << "Keywords:";
	for(it = keywords.begin(); it != keywords.end(); ++it){
		cout << " " << (*it);
	}
	cout << endl;
}

//Prints a list of found constants, in the order that they appeared
void Tokenizer::printConstants(){
	vector<string>::iterator it;
	
	cout << "Constants:";
	for(it = constants.begin(); it != constants.end(); ++it){
		cout << " " << (*it);
	}
	cout << endl;
}

//Prints a list of running errors in the order that they were found
void Tokenizer::printErrors(){
	vector<string>::iterator it;
	int i = 1;
	
	//Print each error on its own line
	for(it = errors.begin(); it != errors.end(); ++it, ++i){
		cout << "Error(" << i << "): " << (*it) << endl;
	}
}

void Tokenizer::findKeywords(string str){
	string keyword; //Stores found keywords

	//Look for capitalised letters
	for(unsigned int i = 0; i < str.length(); ++i){
		//Check for keyword at the end of the string
		if(i == (str.length()-1) && isupper(str[i])){
			//Add char to string keyword
			keyword.push_back(str[i]);
		
			//If keyword found add to stack
			if(isKeyword(keyword)){
				Token token(KEYWORD, keyword);
				keyStack.add(token);
			}
			//Invalid keyword found
			else if(!keyword.empty()){
				//Add Invalid keyword to errors
				errors.push_back("Bad token found: " + keyword);
			}
		}
		//Character is part of a keyword
		else if(isupper(str[i])){
			keyword.push_back(str[i]);
		}
		//Char is not part of a keyword
		else{
			//Keyword found, add to stack
			if(isKeyword(keyword)){
				Token token(KEYWORD, keyword);
				keyStack.add(token);
			}
			//Invalid keyword found
			else if(!keyword.empty()){
				//Add Invalid keyword to errors
				errors.push_back("Bad token found: " + keyword);
			}
			
			//Empty string
			keyword.clear();
		}
	}
}

bool Tokenizer::isKeyword(string word){
	int length = sizeof(KEYWORDS)/sizeof(KEYWORDS[0]);

	for(int i = 0; i < length; ++i){
		if(KEYWORDS[i].compare(word) == 0){
			//Add keyword to keywords vector
			if(!KEYWORDR[i]){
				//Add keyword to keywords
				keywords.push_back(word);
				//Change register
				KEYWORDR[i] = 1;
			}
			
			return true;
		}
	}
	
	return false;
}

void Tokenizer::findConstants(string str){
	string constant;
	
	for(unsigned int i = 0; i < str.length(); ++i){
		//Check for const at end of string
		if(i == (str.length()-1) && isdigit(str[i])){
			//Add char to constant
			constant.push_back(str[i]);
		
			//Check if constant has been found before
			if(!isConstFound(constant)){
				constants.push_back(constant);
			}
		}
		//Char is part of a constant
		else if(isdigit(str[i])){
			constant.push_back(str[i]);
		}
		//Check if constant was found
		else{
			if(!constant.empty()){
				//Check if constant has been found before
				if(!isConstFound(constant)){
					constants.push_back(constant);
				}
			
				//Empty string
				constant.empty();
			}
		}
	}
}

//Checks if a const has already been found
bool Tokenizer::isConstFound(string constant){
	vector<string>::iterator it;

	for(it = constants.begin(); it != constants.end(); ++it){
		if(it->compare(constant) == 0){
			return true;
		}
	}
	
	return false;
}
