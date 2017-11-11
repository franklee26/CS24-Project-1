//node class implementation
//Frank Lee, 1/11

#include "node.h"
#include <string>
using std::string;

//constructor

node::node(){
	integer=0;
	leftnode=NULL;
	rightnode=NULL;
	myoperator='f';
	parent=NULL;
}

//methods

void node::setoperator(char op){
	if (op != '+' && op != '-' && op != '*' && op!= '/'){
		return;
	}
	myoperator=op;
}

void node::setleftnode(node* leftpointer){
	leftnode=leftpointer;
}

void node::setrightnode(node* rightpointer){
	rightnode=rightpointer;
}

void node::setvariable(){
	variable='x';
}

void node::setparent(node* theparent){
	parent=theparent;
}

void node::setinteger(int myvalue){		//perhaps need to check if myvalue lies within [1,9]
	integer=myvalue;
}

//observers

node* node::left() const{
	return leftnode;
}

node* node::right() const{
	return rightnode;
}

int node::value() const{
	return integer;
}

node* node::getparent() const{
	return parent;
}

char node::getoperator() const{
	return myoperator;
}

node* node::getnextleft(node* currnode) const{
	if (currnode->left()==NULL){
		return currnode;
	} else {
		return currnode->left();
	}
}

node* node::getnextright(node* currnode) const{
	if (currnode->right()==NULL){
		return currnode;
	} else {
		return currnode->right();
	}
}

bool node::leftexist(){
	if (leftnode==NULL){
		return false;
	} else return true;
}

bool node::rightexist(){
	if (rightnode==NULL){
		return false;
	} else return true;
}