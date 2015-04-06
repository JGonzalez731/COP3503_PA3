#ifndef STACK_H
#define STACK_H

#include <vector>
#include <string>
#include <iostream>

class Stack{
	public:
		Stack(): size(0), maxSize(0){};
		void add(std::string token){
			tokenStack.push_back(token);
			++size;
			if(size > maxSize) maxSize = size;
		}
		void remove(){
			tokenStack.pop_back();
			if(size > 0) --size;
		}
		void print(){
			std::vector<std::string>::iterator it;
			for(it = tokenStack.begin(); it != tokenStack.end(); ++it){
				std::cout << (*it) << std::endl;
			}
		}
		int length(){ return size; }			//Returns the number of items on the stack
		int maxLength(){ return maxSize; }	//Returns the highest number of items that have been on the stack at one time
		
	private:
		std::vector<std::string> tokenStack;
		int size;
		int maxSize;
};

#endif
