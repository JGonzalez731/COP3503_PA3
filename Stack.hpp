#ifndef STACK_H
#define STACK_H

#include "Token.hpp"

class Stack{
	public:
		void add(Token token){ tokenStack.push_back(token); }
		void remove(){ tokenStack.pop_back(); }
		void print(){
			it = vector<Token>::iterator;
			for(it = tokenStack.begin(); it != tokenStack.end(); ++it){
				cout << it->getType(); << endl;
			}
		}
		
	private:
		vector<Token> tokenStack;
}

#endif
