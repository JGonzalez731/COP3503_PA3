#include <fstream>
#include "TOKEN_CONSTANTS.hpp"
#include <ctype.h>

void Tokenizer::parse(string fileName){

	//Open file
	ifstream fileStream(fileName);
	
	//Check if file opened successfully
	if(!fileStream.is_open()){
		//TODO throw an error
		
		return;
	}
	
	/* Tokenize file line by line */
	string line;
	
	while(getline(fileStream, line)){
		//Look for possible keywords
		findKeywords(line);
		
		//TODO look for more things!
	}
}

void Tokenizer::findKeywords(string str){
	string keyword; //Stores found keywords

	//Look for capitalised letters
	for(int i = 0; i < str.length(); ++i){
		//Character is part of a keyword
		if(isupper(str[i])){
			keyword.push_back(str[i];
		}
		//Char is not part of a keyword
		else{
			//Keyword found, add to stack
			if(isKeyword(keyword)){
				stack.add(keyword);
			}
			
			//Empty string
			keyword.clear();
		}
	}
}

bool Tokenizer::isKeyword(string word){
	for(int i = 0; i < KEYWORDS.length; ++i){
		if(KEYWORDS[i].compare(word) == 0){
			return true;
		}
	}
	
	return false;
}
