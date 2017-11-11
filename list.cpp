//list implementation
//Frank Lee, 30/10

#include "list.h"
#include <string>
#include <iostream>
#include <stdlib.h>
using std::string;

list::list(){
	head=NULL;
}

list::list(node* myhead){
	head=myhead;
}

//the big one, oh my fucking god

list::list(string atomicexpression){
	int length=atomicexpression.length();
	int i=0;
	node* current=new node;
	current->setleftnode(NULL);
	current->setrightnode(NULL);
	while (i<length){
		if (atomicexpression[i]=='('){
			node* n=new node;
			n->setparent(current);
			n->setleftnode(NULL);
			n->setrightnode(NULL);
			if (current->left()==NULL){
				current->setleftnode(n);
			} else {
				current->setrightnode(n);
			}
			current=n;
		} else if (atomicexpression[i]=='+' || atomicexpression[i]=='-' || atomicexpression[i]=='*' || atomicexpression[i]=='/'){
			current->setoperator(atomicexpression[i]);
		} else if (atomicexpression[i]=='x'){
			current->setvariable();
		} else if (atomicexpression[i]=='1' || atomicexpression[i]=='2' || atomicexpression[i]=='3' || atomicexpression[i]=='4' || atomicexpression[i]=='5' || atomicexpression[i]=='6' || atomicexpression[i]=='7' || atomicexpression[i]=='8' || atomicexpression[i]=='9'){
			current->setinteger(atoi(&atomicexpression[i])); //do I need to convert this into int using atoi?
		} else if (atomicexpression[i]==')'){							
			//bloody draw it you idiot
			current=current->getparent();
			head=current;
		}
		i++;
	}
}


//observers

node* list::gethead() const{
	return head;
}
