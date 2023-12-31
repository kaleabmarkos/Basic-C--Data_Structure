/********************************************************************
*** NAME        : Kaleab Gessese                                  ***
*** CLASS       : CSc 300                                         ***
*** ASSIGNMENT  : 5                                               ***
*** DUE DATE    : 11/29/2023                                      ***
*** INSTRUCTOR  : GAMRADT                                         ***
*********************************************************************
*** DESCRIPTION : This is a implimentation file of the graphs ADT.
                  Graphs are implmented here using fixed sized arrays
                  and an ajacency matrix consisting of 0 or more Element
                  values. And using the algorithm known as dijkstra's
                  algorithm it finds the shortest path from a selected vertex
                  to all the other vertices.

********************************************************************/
#include<iostream>
#include "Graph.h"
#include <fstream>
#include<limits>
#include <cstdlib>

using namespace std;
typedef std::string string;

/********************************************************************
*** FUNCTION    : Graph                                           ***
*********************************************************************
*** DESCRIPTION : Parameterized constructor – creates the described
                  graph, file name passed by the user , if no file
                  name is given in default graph file name is "data.dat"
                  and uses setGraph                               ***
*** INPUT ARGS  : const string fileName                           ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Graph::Graph(const string fileName) {
    setGraph(fileName);

}

/********************************************************************
*** FUNCTION    : ~Graph                                          ***
*********************************************************************
*** DESCRIPTION : destructor, does Nothing                        ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
Graph::~Graph(){

}
/********************************************************************
*** FUNCTION    : dijkstra                                        ***
*********************************************************************
*** DESCRIPTION : This function applies the dijkstra's algorithm on
                 the given graph. It Compute the minimum path cost
                 from the selected vertex given to it from the
                 setStart function to all other vertices in a
                 weighted/labeled directed graph.                 ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/

void Graph::dijkstra()
{

    unsigned short startingNode ,index ,x ,minDistance, v, w;
    do{
        //marks all nodes to unvisited
        setVisited();

        //let user set the start node
        startingNode = setStart();
        visited[startingNode] = 1;

        //initialize distances from the start node to all other nodes
        for(index = 0; index < nodeCount; index++)
        { distance[index] = cost[startingNode][index]; }

        //main loop for dijkstra's algorithm
        for(x = 0; x < nodeCount; x++)
        {

             v = 0;
             minDistance = 65535; // large initial value


            //find the unvisitted node with minimum distance
            for ( w = 0; w < nodeCount; ++w) {
                if (!visited[w] && distance[w] < minDistance) {
                    minDistance = distance[w];
                    v = w;
                }
            }

            //mark the found node as visited
            visited[v] = 1;


            //update distance to adjacent nodes
            for( w = 0; w < nodeCount; w++)
            {
                if(visited[w] == 0)
                {
                    //update distance to adjacent nodes
                    if((distance[w]) > (distance[v] + cost[v][w]))
                    {
                        distance[w] = distance[v] + cost[v][w];
                    }
                }
            }
        }
        //display the result
        view();

    } while(restart());

    return;
}


/********************************************************************
*** FUNCTION    : setGraph                                        ***
*********************************************************************
*** DESCRIPTION : The setGraph function in the provided here reads
                  graph data from a file specified by the fileName
                  parameter. It opens the file, checks for successful
                  opening, and exits the program with an error message
                  if the file cannot be opened. The function then reads
                  the number of nodes (nodeCount) from the file and
                  populates a 2D array (cost) with edge weights between
                  nodes.                                          ***
*** INPUT ARGS  : const string fileName                           ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/

void Graph::setGraph(const string fileName){
    unsigned short v,w;

    ifstream graphFile;
    graphFile.open(fileName);

    if (!graphFile){
        cout << "Unable to open the file" << endl;
        exit(EXIT_FAILURE);     //exit the program if it can't open the file.
    }

    graphFile >> nodeCount;


    for(v = 0; v< nodeCount; ++v){
        for(w = 0; w < nodeCount; ++w){
            graphFile >> cost[v][w];
        }
    }

    graphFile.close();

    return;
}

/********************************************************************
*** FUNCTION    : setVisited                                      ***
*********************************************************************
*** DESCRIPTION : Set visited function to set all the nodes to 0
                  or unvisited for the dijkstra's to start with.***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void Graph::setVisited()
{
    for(int i = 0; i < nodeCount; i++)
    {
        visited[i] = 0;
    }

    return;
}

/********************************************************************
*** FUNCTION    : setStart                                        ***
*********************************************************************
*** DESCRIPTION : Set start function to get the starting node.
                  Prompts the user to get the starting node.
                  Invalid if out of range using a do-while loop and
                  returns a valid starting node to the dijkstra's
                  algorithm.                                      ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : startingNode                                    ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
unsigned short Graph:: setStart() const{
    unsigned short startingNode = 0;

    do{
        cout << "Enter which node you would like to start with (0 - "<<nodeCount-1<<"): ";
        cin >> startingNode;

        if(startingNode < 0 || startingNode >= nodeCount){
            cout<<"Error: Invalid starting node. Please enter a valid node." << endl;
        }
        } while (startingNode < 0|| startingNode >= nodeCount);

    return startingNode;
}

/********************************************************************
*** FUNCTION    : view                                           ***
*********************************************************************
*** DESCRIPTION : This function displays the graphs distance array.
                  Starting from 0 to nodeCount for 0-3, and displays
                  the distances in a list kind of form.           ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void Graph::view() const {

    for (unsigned short v = 0; v < nodeCount; v++) {
        cout << "Distance ["<<v <<"] = "<<distance[v]<<endl;
    }
    cout << endl;

    return;
}


/********************************************************************
*** FUNCTION    : restart                                         ***
*********************************************************************
*** DESCRIPTION : A function to rerun the dijkstra's algorithm.   ***
                  This is a boolean function asks for yes or no (y/n)
                  then returns true or false base on the users input.
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : userChoice                                      ***
*** RETURN      : none                                            ***
********************************************************************/
bool Graph::restart() const {
    char userChoice;

    cout << "Do you want to run Dijkstra again on the same graph? (y/n) ";
    cin >> userChoice;

    while (userChoice != 'y' && userChoice != 'n') {
        cout << "Please use 'y' for yes or 'n' for no. ";
        cin >> userChoice;
    }

    return (userChoice == 'y');
}
