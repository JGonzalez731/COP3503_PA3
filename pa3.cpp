#include <iostream>
#include <string>
#include "TOKEN_CONSTANTS.hpp"
#include "Tokenizer.hpp"

using namespace std;

int main(){
	//Create stack object
	Stack stack;
	
	//Bind stack object to tokenizer
	Tokenizer tokenizer(stack);
	
	//Parse the received file
	tokenizer.parse(/* fileName */);
	
	//View the tokens added to the stack
	stack.print();
	
	return 0;
}


//Have multiple stacks
//push back for BEGIN, pop back the BEGIN when you find an END
//Do something similiar for parentheses and maybe statements
