/********************************************************************
*** NAME        : Kaleab Gessese                                  ***
*** CLASS       : CSc 300                                         ***
*** ASSIGNMENT  : 3                                               ***
*** DUE DATE    : 10/18/2023                                      ***
*** INSTRUCTOR  : GAMRADT                                         ***
*********************************************************************
*** DESCRIPTION : This is the implimentation file of the Queue ADT.
Queue implements data in a FIFO manner (First in first out) and allows 
the user to enter data from one end and removes from the other.
This program contains a class initializing a queue, a copy constructor 
to copy the existing queue, destructor remove all elements, enqueue
 inserting an element, dequeue removing an element, two bool returning 
 functions to check if our queue is empty or full and a view function 
 to display elements.

********************************************************************/
#include "Queue.h"
#include <cstdlib>
#include <iostream>
#include <new>

using namespace std;
/********************************************************************
*** FUNCTION    : Queue                                           ***
*********************************************************************
*** DESCRIPTION : Constructor, uses the new operator to           ***
***               initialize an empty array with a size specified ***
***               by the user, or 3 if the user didnt specify any.***
*** INPUT ARGS  : Size                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Queue::Queue(const int Size): QUEUE_SIZE(Size), head(-1), tail(-1)
{queueArray = new (std::nothrow) Element[Size];
    if(queueArray == nullptr)
    {
        cout << "Memory allocation failed."<<endl;
    }
}
/********************************************************************
*** FUNCTION    : Queue                                          ***
*********************************************************************
*** DESCRIPTION : Copy Constructor, uses the new operator to      ***
***               initialize an empty array with a size specified ***
***               by the user, or 3 if no size is given, while obj 
                  is not empty dequeue then enqueue to the temporary queue. 
                  Then while temporary is not empty dequeue from temporary 
                  and enqueue to both obj and new queue           ***
***                                                               ***
*** INPUT ARGS  : obj                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Queue::Queue(Queue & obj): QUEUE_SIZE(obj.QUEUE_SIZE), head(-1), tail(-1)
{
    queueArray = new (std::nothrow) Element[obj.QUEUE_SIZE];

    Queue TemporaryQueue(obj.QUEUE_SIZE);

    Element temporaryElement;

    while(!obj.isEmpty())
    {
        obj.dequeue(temporaryElement);
        TemporaryQueue.enqueue(temporaryElement);
        
    }
    while(!TemporaryQueue.isEmpty())
    {
        TemporaryQueue.dequeue(temporaryElement);
        obj.enqueue(temporaryElement);
        enqueue(temporaryElement);
    }
}
/********************************************************************
*** FUNCTION    : ~Queue                                          ***
*********************************************************************
*** DESCRIPTION : This is the destructor function, while the queue***
***               is not empty, dequeue, then delete queueArray   ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Queue :: ~Queue()
{
    Element t;
    while(!isEmpty())
    {
        dequeue(t);
    }
   
    delete [] queueArray;
    queueArray = nullptr;
 
}
/********************************************************************
*** FUNCTION    : enqueue                                         ***
*********************************************************************
*** DESCRIPTION : If the queue is full print a message            ***
                  "Queue is full". If the queue is empty or       ***
                   if the element to be enqueued if the first one ***
                   add element to the back adjust front and back. ***
                   Else if there are 1 or more elements add       ***
                   element to the back then adjust back           ***
*** INPUT ARGS  : num                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : void                                            ***
********************************************************************/
void Queue::enqueue(const Element num) {
    if (isFull()) {
        cout <<num<<" not added Queue is full" << endl;
        return;
    }

    if (isEmpty()) {
        // If the queue is empty, set head and tail to the first index
        head = 0;
        tail = 0;
    } 
        // If there are 1 or more elements, enqueue the element to the tail and adjust the tail index
    else {
        tail = (tail + 1) % QUEUE_SIZE;            
        }
    queueArray[tail] = num;
   
}
/********************************************************************
*** FUNCTION    : dequeue                                         ***
*********************************************************************
*** DESCRIPTION : If the queue is empty print a message           ***
                  "Queue is Empty". If the queue has 1 element    ***
                   remove element from head adjust head and tail  ***
                   Else if there are 2 or more elements remove    ***
                   element to the head then adjust head           ***
*** INPUT ARGS  : deqel                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : void                                            ***
********************************************************************/
void Queue::dequeue(Element &deqel)
{
    if(isEmpty())
    {
        cout << "Queue is Empty." <<endl;
        return;
    }
    
    deqel = queueArray[head];

    if(head == tail)
    {
        head = -1;
        tail = -1;
    }
    else
    {
        head = (head + 1) % QUEUE_SIZE;
        
    }
    
}
/********************************************************************
*** FUNCTION    : view                                         ***
*********************************************************************
*** DESCRIPTION : The view operation is invoked by the queue to   ***
                  be viewed or displayed. While the queue is not  ***
                  empty dequeue, display and then enqueue it to   ***
                  the tempQueue. Then while the temp Queue is     ***
                  not Empty dequeue from the temp queue and       ***
                  enqueue it back to the original Queue           ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : void                                            ***
********************************************************************/
void Queue::view() {
    // Create a temporary queue
    Queue tempQueue(QUEUE_SIZE);

    Element tempElement;

    cout << "HEAD -> ";
 
    // Move elements from the current queue to the temporary queue for viewing
    while (!isEmpty()) {
        dequeue(tempElement);
        cout << tempElement << " -> ";
        tempQueue.enqueue(tempElement);
    }

     cout <<"TAIL" << endl;

    // Move elements back from the temporary queue to the current queue
    while (!tempQueue.isEmpty()) {
        tempQueue.dequeue(tempElement);
        enqueue(tempElement);
    }
}

/********************************************************************
*** FUNCTION    : isEmpty                                         ***
*********************************************************************
*** DESCRIPTION : If head and tail both are -1 then return true   ***
***               else return false                               ***
***                                                               ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : Bool(True/False)                                ***
********************************************************************/
bool Queue::isEmpty()const
{

    if(head == -1 && tail == -1)
    {
        return true;
    }

    else
    {
        return false;
    }

}
/********************************************************************
*** FUNCTION    : isFull                                            ***
*********************************************************************
*** DESCRIPTION : If tail +1 divided by the queue size have a     ***
                  remainder equal to head then return true else   ***
                  return false.                                   ***
***                                                               ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : Bool(True/False)                                ***
********************************************************************/
bool Queue::isFull() const
{
    
    if(((tail+1)%QUEUE_SIZE) == head)
    {
        return true;
    }
    else
    {
        return false;
    }

}