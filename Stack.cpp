*** DESCRIPTION : The Stack ADT implements a data structure in    ***
*** LIFO (Last In First Out) form that allows the user to add and ***
*** remove elements from one end of a dynamically allocated array.***
*** This class contains methods to initialize a new stack, create ***
*** a copy of an existing stack, remove all elements, insert a new***
*** element to the top of the stack, remove an element from the   ***
*** top of the stack, access an existing element from the top,    ***
*** and view all of the elements in the stack from top to bottom. ***
********************************************************************/

//Includes
#include <iostream>
#include "Stack.h"
using namespace std;


/********************************************************************
*** FUNCTION    : Stack                                           ***
*********************************************************************
*** DESCRIPTION : Constructor, uses the new operator to           ***
***               initialize an empty array with a size specified ***
***               by the user, or 2 if no size is given           ***
*** INPUT ARGS  : size                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
//This function was written inline in the header file


/********************************************************************
*** FUNCTION    : Stack                                           ***
*********************************************************************
*** DESCRIPTION : Copy constructor, while old is not empty, pop   ***
***               from old and push to temp Stack. Then while temp***
***               is not empty, pop from temp and push to both    ***
***               old and new stack                               ***
*** INPUT ARGS  : old                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Stack::Stack(Stack & old) : STACK_SIZE(old.STACK_SIZE), top(0)
{
    //initialize the new stack like the normal constructor
    stackArray = new (std::nothrow) Element [old.STACK_SIZE];

    //a temporary stack of the same size as the one passed in
    Stack tempStack(old.STACK_SIZE);

    //a local variable to hold an element between movements
    Element tempElement = "";

    while(old.top != 0)
    {
        tempElement = old.pop();
        tempStack.push(tempElement);
    }
    while(tempStack.top != 0)
    {
        tempElement = tempStack.pop();
        old.push(tempElement);
        push(tempElement);
    }
}

/********************************************************************
*** FUNCTION    : ~Stack                                          ***
*********************************************************************
*** DESCRIPTION : Destructor, while the stack is not empty, pop.  ***
***               then delete stackArray                          ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Stack::~Stack()
{
    while(top != 0)
    {
        pop();
    }

    delete [] stackArray;
}


/********************************************************************
*** FUNCTION    : push                                            ***
*********************************************************************
*** DESCRIPTION : If the stack is full, print an error message.   ***
***               Else, set top element to pushed, then           ***
***               adjust top index.                               ***
*** INPUT ARGS  : pushed                                          ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : void                                            ***
********************************************************************/
void Stack::push(const Element pushed)
{
    if(top == STACK_SIZE)
    {
        cout << "Error: Stack is full! \"" << pushed << "\" cannot be added!" << endl;
    }
    else
    {
        stackArray[top] = pushed;
        top++;
    }

    return;
}


/********************************************************************
*** FUNCTION    : pop                                             ***
*********************************************************************
*** DESCRIPTION : If the stack is empty, print an error message.  ***
***               Else, reverse top index, then return its value. ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : Element                                         ***
********************************************************************/
Element Stack::pop()
{
    if(top == 0)
    {
        cout << "Error: Stack is empty! Cannot pop an element!" << endl;
        return("error");
    }
    else
    {
        top--;
        return(stackArray[top]);
    }
}


/********************************************************************
*** FUNCTION    : peek                                            ***
*********************************************************************
*** DESCRIPTION : Pop the top element, store its value in peeked, ***
***               "re-push" peeked, then return peeked.           *** 
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : peeked                                          ***
********************************************************************/
Element Stack::peek()
{
    //temporary variable to store top element
    Element peeked;

    peeked = pop();

    //if the stack is empty, return before trying to push peeked = "error"
    if(peeked == "error")
    {
        cout << "Error: Stack is empty! Cannot peek an element!" << endl;
        return("error");
    }

    push(peeked);

    return(peeked);
}

/********************************************************************
*** FUNCTION    : view                                            ***
*********************************************************************
*** DESCRIPTION : While the original stack is not empty, pop,     ***
***               display, and push the top element to a temp     ***
***               stack. Then, while the temp stack is not empty, ***
***               pop from temp and push back to original stack.  ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : void                                            ***
********************************************************************/
void Stack::view()
{
    //a temporary stack of the same size as original
    Stack tempStack(STACK_SIZE);

    //a local variable to hold an element between movements
    Element tempElement = "";

    cout << "TOP -> ";

    while (top != 0)
    {
        tempElement = pop();
        cout << tempElement << " -> ";
        tempStack.push(tempElement);
    }

    cout << "BOTTOM" << endl;

    while(tempStack.top != 0)
    {
        tempElement = tempStack.pop();
        push(tempElement);
    }

    return;
}
