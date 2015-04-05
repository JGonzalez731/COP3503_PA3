#ifndef STACK_H
#define STACK_H

#include "Token.hpp"
#include <vector>
#include <iostream>

class Stack{
	public:
		void add(Token token){ tokenStack.push_back(token); }
		void remove(){ tokenStack.pop_back(); }
		void print(){
			std::vector<Token>::iterator it;
			for(it = tokenStack.begin(); it != tokenStack.end(); ++it){
				std::cout << it->getType() << std::endl;
			}
		}
		
	private:
		std::vector<Token> tokenStack;
};

#endif
