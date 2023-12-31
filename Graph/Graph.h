/********************************************************************
*** NAME        : Kaleab Gessese                                  ***
*** CLASS       : CSc 300                                         ***
*** ASSIGNMENT  : 5                                               ***
*** DUE DATE    : 11/29/2023                                      ***
*** INSTRUCTOR  : GAMRADT                                         ***
*********************************************************************
*** DESCRIPTION : This is a header file of the graphs ADT.
                Graphs in data structures are non-linear data structures
                made up of a finite number of nodes or vertices and the
                edges that connect them. Graphs in data structures are
                used to address real-world problems in which it represents
                the problem area as a network like telephone networks,
                circuit networks, and social networks.

********************************************************************/
#pragma once
#include<iostream>

using namespace std;

class Graph {
        public: // exportable
// General description of each of the ADT operations/functions – exportable operations only
            /********************************************************************
*** FUNCTION    : Graph                                           ***
*********************************************************************
*** DESCRIPTION : Parametiraized constructor,  creates the described
                 graph file name passed in default graph file name
                 data.dat, and will use that if nothing is passed in.
*** INPUT ARGS  : const string = "data.dat"(if nothing is passed in the main.cpp page)                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
            explicit Graph(const string = "data.dat");
            /********************************************************************
*** FUNCTION    : ~Graph                                          ***
*********************************************************************
*** DESCRIPTION : Destructor, does nothing                        ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
            ~Graph();
            /********************************************************************
*** FUNCTION    : dijkstra                                           ***
*********************************************************************
*** DESCRIPTION : Applies the dijkstra's algorithm on a given graph.
                Dijkstra's Algorithm finds the shortest path between
                a given node (which is called the "source node") and
                all other nodes in a graph. This algorithm uses the
                weights of the edges to find the path that minimizes
                the total distance (weight) between the source node
                and all other nodes.
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
            void dijkstra();
    private: // non-exportable
// No private member documentation – implementation details are hidden/abstracted away
            typedef unsigned short Element;
            enum {GRAPH_LIMIT = 15};
            Graph(const Graph &) = delete;
            void setGraph(const string);
            void setVisited();
            unsigned short setStart() const;
            void view() const;
            bool restart() const;
            Element cost[GRAPH_LIMIT][GRAPH_LIMIT];
            Element distance[GRAPH_LIMIT];
            bool visited[GRAPH_LIMIT];
            unsigned short nodeCount;
    };
