//list implementation
//Frank Lee, 1/11

#ifndef LIST_H
#define LIST_H
#include "node.h"
#include <string>
using std::string;

class list{

public:
	//constructors
	list();								//defaults to NULL head
	list(string atomicexpression);		//creates actual data structure. DID I FUCKING DO IT???
	list(node* myhead);					//points head to given node
	//observers
	node* gethead() const;

private:
	node* head;
};
#endif