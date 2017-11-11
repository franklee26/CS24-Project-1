//CS24 Proj 1; Frank Lee 27/10
#ifndef NODE_H
#define NODE_H
#include <string>
using std::string;

class node{

public:
	//constructor: do we need one? Apparently yes. 

	node();										//defaults to integer=0 (out of range), operator=f, left/right=NULL and parent=NULL

	//methods

	void setoperator(char op);
	void setleftnode(node* leftpointer);
	void setrightnode(node* rightpointer);
	void setvariable();							//sets variable to x by default, kind of redundant?
	void setparent(node* theparent);
	void setinteger(int myvalue);

	//oberservers

	node* left() const;			//recover the left pointer
	node* right() const;		//recover the right pointer
	int value() const;			//recover the integer
	node* getparent() const;	//recover parent node
	char getoperator() const;

	node* getnextleft(node* currnode) const; //move to the next linked node (if there is one) for the left
	node* getnextright(node* currnode) const; //these seem redundant. Remove?

	bool leftexist();			//not very useful... could just use if (left()!=NULL)...
	bool rightexist();
	
private:
	char myoperator;			//+,-,*,/ default is set to 'f'
	node* leftnode;				//default to NULL
	node* rightnode;			//default to NULL
	string variable;			//not sure how useful this is...
	int integer;				//should be [1-9] and defaults to 0
	node* parent;				//defaults to NULL and must be manually allocated
};
#endif