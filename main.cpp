//main function for CS24 proj
//Frank Lee 5/11

#include "node.h"
#include "list.h"
#include "expression.h"
#include "main.h"			//provides userprompt()
#include <iostream>
#include <string>

int main(){
	/* //TESTING MECHANISMS
	string work="(((x+3)+((x*2)/(x-3)))*((x+7)-((x+2)*(x/2))))";

	string easy="((x+2)-(x*3))";


	list l(work);
	list g(easy);
	expression e(l.gethead());
	expression f(g.gethead());

	std::cout<<e.infixstring()<<std::endl;
	std::cout<<e.infixstring()<<std::endl;
	std::cout<<e.prefixstring()<<std::endl;
	std::cout<<e.postfixstring()<<std::endl;
	std::cout<<f.postfixstring()<<std::endl;
	*/
	string expr;
	std::cout<<"Please enter your atomic expression or enter 'q' to quit: ";
	std::cin>>expr;
	if (expr=="q"){
		std::cout<<"Exiting..."<<std::endl;
		return 0;
	} else{
		std::cout<<std::endl;
		userprompt(expr);
		main();
	}
	return 0;
}