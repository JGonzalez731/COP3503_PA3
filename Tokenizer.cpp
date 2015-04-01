#include <fstream>

void Tokenizer::parse(string fileName){

	//Open file
	ifstream fileStream(fileName);
	
	//Check if file opened successfully
	if(!fileStream.is_open()){
		//TODO send a msg to ouput or throw or use boolean
		return;
	}
	
	/* Tokenize file line by line */
	string line;
	
	while(getline(fileStream, line)){
		//TODO MAGIC
	}
}
