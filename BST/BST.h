
/*********************************************************************
*** DESCRIPTION : This is the header file of the BST ADT.
A binary tree is a nonlinear linked structure. It is nonlinear because
each node can point to two other nodes. This header file defines a BST
class that provides operations for creating, modifying, and viewing the tree.
It includes functions for inserting and removing elements, searching for elements, 
and various ways to view the tree's contents (preorder, inorder, postorder).
The BST class encapsulates the implementation details of the tree and
ensures that the tree remains balanced and sorted at all times.
It provides methods for creating a deep copy of a tree and for destroying the 
tree when it's no longer needed.

********************************************************************/
#pragma once
typedef int Element;
struct Node;
typedef Node *NodePtr;
struct Node{
        Element element;
        NodePtr left,right;
};

class BST{
    public:          //exportable 
    /********************************************************************
*** FUNCTION    : BST                                             ***
*********************************************************************
*** DESCRIPTION : default construnctor                            ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        BST();
        /********************************************************************
*** FUNCTION    : BST                                             ***
*********************************************************************
*** DESCRIPTION : copy constructor                                ***
*** INPUT ARGS  : BST &obj (that is the bst to br copied)         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        BST(const BST&);
        /********************************************************************
*** FUNCTION    : ~BST                                           ***
*********************************************************************
*** DESCRIPTION : Destructor. To destroy an existing BST.         ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        ~BST();
        /********************************************************************
*** FUNCTION    : insert                                     ***
*********************************************************************
*** DESCRIPTION : Inserts a new key node to the BST               ***
*** INPUT ARGS  : Element                                         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        void insert(const Element);
        /********************************************************************
*** FUNCTION    : remove                                     ***
*********************************************************************
*** DESCRIPTION : Locates an existing key node to be removed      ***
*** INPUT ARGS  : Element                                         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        void remove(const Element);
        /********************************************************************
*** FUNCTION    : Search                                     ***
*********************************************************************
*** DESCRIPTION : Returns a pointer to an existing key node       ***
*** INPUT ARGS  : Element                                         ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        NodePtr search(const Element) const;
        /********************************************************************
*** FUNCTION    : PreorderView                                     ***
*********************************************************************
*** DESCRIPTION : To view the BST in order of Visit the current node,
                  Go left then Go right                           ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        void preorderView() const;
        /********************************************************************
*** FUNCTION    : inorderView                                     ***
*********************************************************************
*** DESCRIPTION : To view the BST in order of Go left ,           ***
                  Visit the current node then Go right            ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        void inorderView() const;
        /********************************************************************
*** FUNCTION    : postorderView                                     ***
*********************************************************************
*** DESCRIPTION : To view the BST in order of Go left ,           ***
                  Go right then Visit the current node            ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
        void postorderView() const;
        

    private:                              //non-exportable //No documentation
        NodePtr root;
        void copy(const NodePtr);
        void destroy(NodePtr&);
        void removeNode(NodePtr&);
        void findMaxNode(NodePtr&, NodePtr&);
        void insert(NodePtr&, const Element);
        void remove(NodePtr&, const Element);
        NodePtr search(const NodePtr, const Element) const;
        void preorderView( const NodePtr) const;
        void inorderView( const NodePtr) const;
        void postorderView( const NodePtr) const;
       
};
