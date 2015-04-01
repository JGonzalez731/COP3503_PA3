#include <string>

#ifndef TOKEN_CONSTANTS_H
#define TOKEN_CONSTANTS_H

//Token categories
const int KEYWORD = 200;
const int IDENTIFIER = 201;
const int CONSTANT = 202;
const int OPERATOR = 203;
const int DELIMITER = 204;

//Keyword types
const string BEGIN = "BEGIN";
const string END = "END";
const string FOR = "FOR";
const string WHILE = "WHILE";
const string IF = "IF";
const string ELSE = "ELSE";
const string ESLEIF = "ELSEIF";

//Delimiter types
const char OPEN_PAR = '(';
const char CLOSE_PAR = ')';
const char SEMI = ';';
const char COMMA = ',';

//Operator types
const string PLUS = "+";
const string MINUS = "-";
const string MULTIPLY = "*";
const string DIVIDE = "/";
const string INCREMENT = "++";
const string DECREMENT = "--";
const string ASSIGNMENT = "=";
const string EQUAL_TO = "==";
const string GREATER_THAN = ">";
const string LESS_THAN = "<";
const string AND = "&&";
const string OR = "||";
const string NOT = "!";

//Constant types can be any number.

//Identifier types can only be a lowercase string

#endif
