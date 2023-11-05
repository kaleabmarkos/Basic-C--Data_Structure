/********************************************************************
*** NAME        : Kaleab Gessese                                  ***
*** CLASS       : CSc 300                                         ***
*** ASSIGNMENT  : 3                                               ***
*** DUE DATE    : 10/18/2023                                      ***
*** INSTRUCTOR  : GAMRADT                                         ***
*********************************************************************
*** DESCRIPTION : This is the header file of the Queue ADT.
Queue implements data in a FIFO manner (First in first out) and allows 
the user to enter data from one end and removes from the other.
This program contains a class initializing a queue, a copy constructor 
to copy the existing queue, destructor remove all elements, enqueue
 inserting an element, dequeue removing an element, two bool returning 
 functions to check if our queue is empty or full and a view function 
 to display elements.

********************************************************************/
#ifndef QUEUE_H
#define QUEUE_H
#include<iostream>
#include<new>
#include <cstdlib>

using namespace std;

typedef int Element;
typedef Element *ElementPtr;

class Queue{
    public:
        /********************************************************************
        *** FUNCTION    : Queue                                           ***
        *********************************************************************
        *** DESCRIPTION : Constructor, for the Queue class.               ***
                         This constructor initializes a Queue instance 
                         with a specified size.                           ***
        *** INPUT ARGS  : Size                                            ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : none                                            ***
        ********************************************************************/
        explicit Queue(const int Size = 3);
        /********************************************************************
        *** FUNCTION    : Queue                                           ***
        *********************************************************************
        *** DESCRIPTION : Copy constructor, to create a duplicate         ***
        *** INPUT ARGS  : Queue &obj (that is the queue to be copied)     ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : none                                            ***
        ********************************************************************/
         Queue(Queue &);
        /********************************************************************
        *** FUNCTION    : ~Queue                                          ***
        *********************************************************************
        *** DESCRIPTION : Destructor, removes all elements from the queue,***
        ***               leaving an initialized empty queue              ***
        *** INPUT ARGS  : none                                            ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : none                                            ***
        ********************************************************************/
        ~Queue();
        /********************************************************************
        *** FUNCTION    : enqueue                                         ***
        *********************************************************************
        *** DESCRIPTION : add an element to the queue and adjusts head and
                        tail or tail depending on what was or was not 
                        already there                                     ***
        *** INPUT ARGS  : element to be enqueued                          ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : void                                            ***
        ********************************************************************/
        void enqueue(const Element);
         /********************************************************************
        *** FUNCTION    : dequeue                                         ***
        *********************************************************************
        *** DESCRIPTION : removes an element from the queue and adjusts head and
                        tail or head depending on what was or was not 
                        already there                                     ***
        *** INPUT ARGS  : reference to type Element                       ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : void                                            ***
        ********************************************************************/
        void dequeue(Element &);
         /********************************************************************
        *** FUNCTION    : view                                         ***
        *********************************************************************
        *** DESCRIPTION : displays the queue element from haid to tali    ***
        *** INPUT ARGS  : none                                            ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : void                                            ***
        ********************************************************************/
        void view();
    private:
        const short QUEUE_SIZE;
        ElementPtr queueArray;
        short head, tail;
        /********************************************************************
        *** FUNCTION    : isEmpty                                         ***
        *********************************************************************
        *** DESCRIPTION : checks if the queue is empty or not             ***
        *** INPUT ARGS  : none                                            ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : bool(True/False)                                ***
        ********************************************************************/
        bool isEmpty()const;
        /********************************************************************
        *** FUNCTION    : isFull                                          ***
        *********************************************************************
        *** DESCRIPTION : checks if the queue is full or not              ***
        *** INPUT ARGS  : none                                            ***
        *** OUTPUT ARGS : none                                            ***
        *** IN/OUT ARGS : none                                            ***
        *** RETURN      : bool(True/False)                                ***
        ********************************************************************/
        bool isFull()const;

};

#endif