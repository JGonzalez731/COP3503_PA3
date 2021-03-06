#ifndef TOKEN_H
#define TOKEN_H

class Token{
	public:
		Token(int category, std::string type): category(category), type(type){}
		int getCategory(){ return category; }
		std::string getType(){ return type; }
	
	private:
		int category;
		std::string type;
};

#endif
