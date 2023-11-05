*********************************************************************
*** DESCRIPTION : User defined Abstract Data type(ADT) Stack. 
 The stack supports basic stack operations such as push, pop, peek, and view. The stack's size 
 is fixed and set during instantiation, specified by the STACK_SIZE member. 
 The class encapsulates private members like the stack array (stackArray),
  the top index of the stack (top), and provides methods to interact 
with the stack, adhering to the principles of a stack data structure.***
********************************************************************/
#ifndef STACK_H
#define STACK_H

#include<iostream>


typedef std::string Element;
typedef Element *ElementPtr;

class Stack{
    public:
         //Merged Constructor declared Inline
         explicit Stack(const int size = 2 ) : STACK_SIZE(size), top(0){stackArray = new(std::nothrow) Element[size];}
         Stack(Stack &);
         ~Stack();
         void push(const Element);
         Element pop();
         Element peek();
         void view();
         void processStack(Stack& myStack);
    private:
         const int STACK_SIZE;
         ElementPtr stackArray;
         int top;     

};

#endif
