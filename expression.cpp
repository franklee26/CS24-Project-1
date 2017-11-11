//expression.cpp implementation for expression class
//Frank Lee 3/11

#include "expression.h"
#include <string>
#include <iostream>
using std::string;

expression::expression(){
	head=NULL;
}

expression::expression(node* header){
	head=header;
}

/* void expression::infixstring(node* head){
	if (head->left()==NULL){
		std::cout<<"x"<<head->getoperator()<<head->value()<<")";
		head=head->getparent();
		int i=0;
		while (head->right()!=NULL){
			head=head->right();
			i++;
		}
		for (int k=0; k<=i; k++){
			head=head->getparent();
		}
		if (i==1){

		}
	}
	else if (head->left()!=NULL){
		head=head->getnextleft(head);
		std::cout<<"(";
		infixstring(head);
	} else if (head->right()!=NULL){
		head=head->getnextright(head);
	}
}

*/

/*
void expression::infixstring(node* head){
	if (head->leftexist()){
		while (head->leftexist()){
			head=head->getnextleft(head);
			std::cout<<"(";
		}
		std::cout<<"x"<<head->getoperator()<<head->value()<<")";
		head=head->getparent();
		std::cout<<head->getoperator();
		if (head->rightexist()){
			if (head->right()->leftexist()){
				std::cout<<"(";
			}
			infixstring(head->right());
			if (head->right()->leftexist()){
				std::cout<<")";
				if (head->getparent()!=NULL){
					std::cout<<")";
				}
			} else{
				head=head->getparent();
				infixstring(head->right());
			}
		}
	} else {
		std::cout<<"("<<"x"<<head->getoperator()<<head->value()<<")";
	}
}
*/

/*

void expression::infixstring(node* head){
	while (head->left()!=NULL || head->right()!=NULL){
		if (head->left()!=NULL){
		while (head->left() != NULL){
			std::cout<<"(";
			head=head->left();
		}
		std::cout<<"x"<<head->getoperator()<<head->value()<<")";
		head=head->getparent();
		head->setleftnode(NULL);
		std::cout<<head->getoperator();
	
		head=head->right();
	
		std::cout<<"(";
		infixstring(head);
		head=head->getparent();
	}
	else if (head->left()==NULL){
		std::cout<<"(x"<<head->getoperator()<<head->value()<<")";
		head=head->getparent();
		std::cout<<")";
		head->setleftnode(NULL);
	}
	}
}
*/

string expression::infixstring(){
	string x;
	while (head->left()!=NULL || head->right()!=NULL || head->getoperator()!='f'){
		if (head->left()!=NULL){
			while (head->left()!=NULL){
				head=head->left();
				x=x+"(";
			}
			x=x+"x";
			x+=head->getoperator();
			x=x+std::to_string(head->value());
			x=x+")";
			head=head->getparent();
			head->setleftnode(NULL);
		} else if (head->left()==NULL && head->right()!=NULL){
			x+=head->getoperator();
			x=x+"(";
			head=head->right();
		} else if (head->left()==NULL && head->right()==NULL){
			if (head->value()==0){
				head=head->getparent();
				x=x+")";
				if (head->left()!=NULL){
					head->setleftnode(NULL);
				} else if (head->right()!=NULL){
					head->setrightnode(NULL);
				}
			} else {
				//x=x+"(";
				x=x+"x";
				x+=head->getoperator();
				x=x+std::to_string(head->value());
				head=head->getparent();
				x=x+")";
				head->setrightnode(NULL);
			}
		} 
	}
	list copylist(x);
	node* newhead=new node;
	newhead=copylist.gethead();
	*head=*newhead;
	return x;
}

string expression::prefixstring(){								//This seems to change the actual list?
	string x=infixstring();	
	int len=x.length();
	int k=0;
	for (int i=0; i<len; i++){
		if (x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			for (int l=0; l<i; l++){
				if (x[l]=='('){
					k=l;
				}
			} x[k]=x[i];
			x[i]=' ';
		}
	}
	int i=0;
	while (i<len){
		if (x[i]==')'){
			x[i]=' ';
		}
		i++;
	}string y;
	int j=0;
	while (j<len){
		if (x[j]!=' '){
			y=y+x[j];
		}
		j++;
	}
	return y;
}

string expression::postfixstring(){
	string x=infixstring();
	int len=x.length();
	for (int i=len-1; i>=0; i--){
		if (x[i]=='+'||x[i]=='-'||x[i]=='*'||x[i]=='/'){
			int k=i;
			while (x[k]!=')' && k<len){
				k++;
			} x[k]=x[i];
			x[i]=' ';
		}
	}
	int i=0;
	while (i<len){
		if (x[i]=='('){
			x[i]=' ';
		}
		i++;
	}string y;
	int j=0;
	while (j<len){
		if (x[j]!=' '){
			y=y+x[j];
		}
		j++;
	}
	return y;
}