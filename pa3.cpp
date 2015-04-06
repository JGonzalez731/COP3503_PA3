#include "pa3.hpp"

using namespace std;

int main(){
	//Prompt user for file location
	string filePath;
	cout << "INPUT> Please enter the file path: ";
	cin >> filePath;

	//Initialize a tokenizer to parse the file
	Tokenizer tokenizer;
	
	//Parse the received file
	tokenizer.parse(filePath);
	
	//Display the loop depth
	cout << "OUTPUT> ";
	tokenizer.printLoopDepth();
	cout << endl;
	
	//Display found keywords
	tokenizer.printKeywords();
	
	//Display found identifiers
	tokenizer.printIdentifiers();
	
	//Display found constants
	tokenizer.printConstants();
	
	//Display found operators
	tokenizer.printOperators();
	
	//Display found delimiters
	tokenizer.printDelimiters();
	cout << endl;
	
	//Display errors
	tokenizer.printErrors();
	
	return 0;
}
