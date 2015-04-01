#ifndef TOKEN_H
#define TOKEN_H

class Token{
	public:
		Token(int category, string type): category(category), type(type){}
		int getCategory(){ return category; }
		string getType(){ return type; }
	
	private:
		const int category;
		const string type;
};

#endif
