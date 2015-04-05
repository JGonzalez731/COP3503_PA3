#include <iostream>
#include <string>
#include "Tokenizer.hpp"

using namespace std;

int main(){
	//Initialize a tokenizer to parse the file
	Tokenizer tokenizer;
	
	//Parse the received file
	tokenizer.parse("test.txt");
	
	//Display found keywords
	tokenizer.printKeywords();
	
	//Display found constants
	tokenizer.printConstants();
	
	//Display errors
	tokenizer.printErrors();
	
	return 0;
}


//Have multiple stacks
//push back for BEGIN, pop back the BEGIN when you find an END
//Do something similiar for parentheses and maybe statements
