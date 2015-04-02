#ifndef TOKENIZER_H
#define TOKENIZER_H

#include "Stack.hpp"

class Tokenizer{
	public:
		Tokenizer(Stack stack): stack(stack);
		void parse(string fileName);
	private:
		Stack stack;
		void findKeywords(string str);
}

#endif
