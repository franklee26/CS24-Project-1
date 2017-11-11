# Frank's guide for CS24 project 1: Atomic Expressions

## Brief summary:

There are a total of 8 files for this project. We have three important classes to work:

1. node (from `node.h`)
2. list (from `list.h`)
3. expression (from `expression.h`)

The list class works to convert a string atomic expression i.e (x+3) into a binary node tree (which obviously uses the node class). Then, the expression class uses this binary tree to create an infix expression (x+3), an prefix expression +x3 and an postfix expression x3+. The `main.h` file provides our main implementation a way for users to input a correct atomic expression and then use the classes mentioned above.

## node.h

### TO-DO:

1. Rename class to Node (to capital N)
2. Clean up any redundancy

### Break down:

The key point worth mentioning is that the node class has a constructor that initialises a node to have an `myoperator` value of `f`, an `integer` value of 0 and all node pointers to point to `NULL`. The other methods and observers are pretty straight forward.  




