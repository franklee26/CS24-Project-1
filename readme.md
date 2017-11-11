# Frank's guide for CS24 project 1: Atomic Expressions
##### Email: franklee@umail.ucsb.edu 
##### 10/11

## Brief summary:

There are a total of 8 files for this project. We have three important classes to work:

1. node (from `node.h`)
2. list (from `list.h`)
3. expression (from `expression.h`)

The list class works to convert a string atomic expression i.e (x+3) into a binary node tree (which obviously uses the node class). Then, the expression class uses this binary tree to create an infix expression (x+3), an prefix expression +x3 and an postfix expression x3+. The `main.h` file provides our main implementation a way for users to input a correct atomic expression and then use the classes mentioned above.

## node.h

#### TO-DO:

1. Rename class to Node (to capital N)
2. Clean up any redundancy

#### Break down:

The key point worth mentioning is that the node class has a constructor that initialises a node to have an `myoperator` value of `f`, an `integer` value of 0 and all node pointers to point to `NULL`. The other methods and observers are pretty straight forward.  

## list.h

#### TO-DO:

1. Possibly remove the `list()` and `list(node* myhead)` constructors?

#### Break down:

The important feature is the constructor `list(string atomixexpression)`, which converts our string into this binary node tree. See the implementation of this in the corresponding `list.cpp` file. This algorithm was basically given to us in the project PDF, but we needed to add where our private member `head` pointed to after the tree was created. 

## expression.cpp

#### TO-DO:

1. General clean up (make sure code is organised, weird comments made by me should be removed soon) 
2. Bug testing! (Everything seems to work, but I need to make sure about everything!)

#### Break down:

This is the big one, and was bloody difficult. The `infixstring()` method does not need a parameter, since we have a head node pointing to the list in our private declaration. I tried a recursive means of doing this, but I didn't make it... it got really messy. So, I chose an iterative approach where we first traverse all the way to the very bottom left leaf via the iterative call 
```c++
head=head->left();
```
We then go through the node, and after we're finished we traverse back to the parent node via
```c++
head=head->getparent();
```
and then set
```c++
head->left()=NULL;
```
and then we iterate through the while loop. This time, since the left node is pointing to NULL we are forced to go into the right node and do the same (more or less) thing. There are bunch of exceptions, as you can see by the multiple `else if` statements but if you read through it, it should make some sense (it took me forever to figure this out). 

So you can see that everytime we are done with a node, we just traverse back to its parents and set the pointer to that ndoe to NULL. Eventually, we will be stuck at the head so how will it know to stop at the head? The trick was to realise that our node constructor automatically sets `myoperator` to the `char` value `f`. So therefore, only the head node will have `myoperator=f`. You can see this fact being used in out main while-loop. The last couple of lines for this definition is there because this function call actually destroys our list. I tried using a `const` method, but I couldn't do that so if there is a better way go ahead! Otherwise, I just made another copy of our original list by using our newly constructed string and the list constructor. Finally, let our original head point to this copy and we're done. 

Now, the definition for `prefixstring()` and `postfixstring()` is easy. We simply take our constructed prefix string, and iterate through it. We make sure we place the operators in its correct position and we remove the old operators by replacing it with the empty space `' '`. We then have to employ extra loops to first make sure we remove the extra parentheses and also to make sure we remove the extra spaces and fill the gaps.  

## main.h

#### TO-DO:

1.) Finalise and make sure this is all I need? (is this enough...?)
2.) Rename to `string.h` and `string.cpp` respectfully. 

#### Break down:

This file provides the user implementation for the `main.cpp` file. Essentially, all it does is it takes an input string (provided by the user) and just prints out the infix, prefix and postfix expressions using the `expression` class. Besides this, I can't think of anything else to implement! Are we sure this is all we need? 

## The end! Let me know if something is wrong, or if you found a better way or even if you cleaned things up!




