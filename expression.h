//expression class
//Frank Lee 3/11

#include <string>
#include "list.h"
#ifndef EXPRESSION_H
#define EXPRESSION_H
using std::string;

class expression{
public:
	//constructors
	expression();				//needed to change class to the following
	expression(node* header);
	//methods
	string infixstring();		//returns infix expression provided input head node for list
	string prefixstring();
	string postfixstring();

private:
	node* head;					//head node for tree-list
};
#endif