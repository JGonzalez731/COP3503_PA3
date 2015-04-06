#include <iostream>
#include <string>
#include "Tokenizer.hpp"

using namespace std;

int main(){
	//Initialize a tokenizer to parse the file
	Tokenizer tokenizer;
	
	//Parse the received file
	tokenizer.parse("test.txt");
	
	//Display the loop depth
	tokenizer.printLoopDepth();
	
	//Display found keywords
	tokenizer.printKeywords();
	
	//Display found identifiers
	tokenizer.printIdentifiers();
	
	//Display found constants
	tokenizer.printConstants();
	
	//Display found delimiters
	tokenizer.printDelimiters();
	
	//Display errors
	tokenizer.printErrors();
	
	return 0;
}
