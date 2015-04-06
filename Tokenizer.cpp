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
	
	/* Turn file into string */
	string file;
	string line;
	
	while(getline(fileStream, line)){
		file.append(line + '\n');
	}
	file.erase(file.begin() + (file.length()-1));
	
	//Look for possible keywords
	findKeywords(file);
	
	//Look for possible constants
	findConstants(file);
	
	//TODO look for more things!
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
		
			//Keyword found
			if(isKeyword(keyword)){
				if(keyword.compare("FOR") == 0 ||
				   keyword.compare("WHILE") == 0 ||
				   keyword.compare("IF") == 0 ||
				   keyword.compare("ELSE") == 0 ||
				   keyword.compare("ELSEIF") == 0){
					//Keyword is trailing, add to errors
					errors.push_back("Trailing keyword " + keyword);
				}
				else if(keyword.compare("BEGIN") == 0){
					//Begin will be missing an end, add to errors
					errors.push_back("Missing keyword END");
				}
				else if(keyword.compare("END") == 0){
					//Remove 1 loop from stack
					loopStack.remove();
					//Remove 1 begin from stack
					if(beginStack.length() > 0){
						beginStack.remove();
					}
					//There are more ends than begins
					else{
						errors.push_back("Missing keyword BEGIN");
					}
				}
			}
			//Invalid keyword found
			else if(!keyword.empty()){
				//Add Invalid keyword to errors
				errors.push_back("Invalid keyword " + keyword);
			}
		}
		//Character is part of a keyword
		else if(isupper(str[i])){
			keyword.push_back(str[i]);
		}
		//Char is not part of a keyword
		else{
			//Keyword found
			if(isKeyword(keyword)){
				if(keyword.compare("FOR") == 0){
					//Add to loop stack
					loopStack.add(keyword);
					//TODO check for delimiters
					//TODO check for begin on next line
				}
				else if(keyword.compare("WHILE") == 0){
					//Add to loop stack
					loopStack.add(keyword);
					//Check for logical expression
					if(str[i] != OPEN_PAR){
						errors.push_back("Missing logical expression for WHILE loop");
					}
					//TODO check for begin on next line
				}
				else if(keyword.compare("IF") == 0){
					//Add to branch list
					branches.push_back(keyword);
					
					//Check for logical expression
					if(str[i] != OPEN_PAR){
						errors.push_back("Missing logical expression for IF statement");
					}
				}
				else if(keyword.compare("ELSEIF") == 0){
					//Add branch to branches list
					branches.push_back(keyword);
					
					//Check for logical expression
					if(str[i] != OPEN_PAR){
						errors.push_back("Missing logical expression for ELSEIF statement");
					}
					
					//Check if proceeded by an if or elseif statement
					if(IF.compare(branches.back()) != 0 && ELSEIF.compare(branches.back()) != 0){
						errors.push_back("No preceding IF or ELSEIF for branch");
					}
				}
				else if(keyword.compare("ELSE") == 0){
					//Add branch to branches list
					branches.push_back(keyword);
					
					//Check if proceeded by an if or elseif statement
					if(IF.compare(branches.back()) != 0 && ELSEIF.compare(branches.back()) != 0){
						errors.push_back("No preceding IF or ELSEIF for branch");
					}
				}
				else if(keyword.compare("BEGIN") == 0){
					//Add begin to stack
					beginStack.add(keyword);
				}
				else if(keyword.compare("END") == 0){
					//Remove 1 loop from stack
					loopStack.remove();
					//Remove 1 begin from stack
					if(beginStack.length() > 0){
						beginStack.remove();
					}
					//There are more ends than begins
					else{
						errors.push_back("Missing keyword BEGIN");
					}
				}
			}
			//Invalid keyword found
			else if(!keyword.empty()){
				//Add Invalid keyword to errors
				errors.push_back("Invalid keyword " + keyword);
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
				constant.clear();
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
