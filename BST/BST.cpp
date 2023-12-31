/********************************************************************
*** NAME        : Kaleab Gessese                                  ***
*** CLASS       : CSc 300                                         ***
*** ASSIGNMENT  : 4                                               ***
*** DUE DATE    : 11/08/2023                                      ***
*** INSTRUCTOR  : GAMRADT                                         ***
*********************************************************************
*** DESCRIPTION : This is the implimentation file of the BST ADT.
The data structure is called a tree because it resembles an upside-down
tree.It is anchored at the top by a tree pointer , which is like the head pointer in a 
standard linked list. The first node in the list is called the root
node. The root node has pointers to two other nodes, which are 
called children, or child nodes . Each of the children has its own
set of two pointers and can have its own children. The constructor
initializes the root to null to start with. Also has the operations
including copy and destroy in a recursive manner. And supporting
operations to handle the recursion.

********************************************************************/

#include<iostream>
#include<new>
#include "BST.h"
using namespace std;
/********************************************************************
*** FUNCTION    : BST                                             ***
*********************************************************************
*** DESCRIPTION : Default constructor, used to intialize root pointer
                  to null to start with.                          ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
BST::BST():root(nullptr){}    

/********************************************************************
*** FUNCTION    : BST                                             ***
*********************************************************************
*** DESCRIPTION : Copy Constructor, uses the new operator to inititalize 
                  an empty BST. Check new and calls the copy function 
                  to handle the recursion                         ***
*** INPUT ARGS  : obj                                             ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
BST::BST(const BST &obj):root(nullptr){
    
    root = new (std::nothrow) Node;
    if(root == nullptr){
        cout << "Memory allocation failed."<<endl;
    }

    root->element = obj.root->element;

    copy(obj.root);
}
/********************************************************************
*** FUNCTION    : ~BST                                            ***
*********************************************************************
*** DESCRIPTION : Destructor function. We use recursion here
But we can not have recusion in the destructor. So this destructor 
calls a destroy function or a function that does the recursion for 
it.                                                               ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
BST::~BST(){
    destroy(root);
}
/********************************************************************
*** FUNCTION    : copy                                            ***
*********************************************************************
*** DESCRIPTION : Recursively copies the elements to new BST. This is 
                  part of the copy constructor. It copies the elements
                  in a preorder fashion.                          ***
*** INPUT ARGS  : const NodePtr sNode                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::copy(const NodePtr sNode){
    if (sNode == nullptr) {
        return;                 //if the current node is null just return
}

    insert(sNode->element);     //insert the current nodes element into the new BST

    //recursively copy the left and right subtrees
    if(sNode -> left != nullptr)        
    {
        copy(sNode->left);       
    }
    if(sNode -> right != nullptr)
    {
        copy(sNode->right);
    }
}
/********************************************************************
*** FUNCTION    : destroy                                          ***
*********************************************************************
*** DESCRIPTION : This function is used to recursively delete all nodes
 in the BST and release the memory they occupy. It starts from the
  root and traverses the entire tree in a post-order fashion. 
  To deallocate memory and clear the entire BST when it's no
   longer needed                                               ***
*** INPUT ARGS  : NodePtr &n                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::destroy(NodePtr& n)
{
    if(n == nullptr)
    {
        return;
    }

    destroy(n->left);
    destroy(n->right);

    delete n;
    n=nullptr;
}
/********************************************************************
*** FUNCTION    : insert                                          ***
*********************************************************************
*** DESCRIPTION : This function inserts a new node with the specified 
element into the BST. It calls the recursive version of insert with
 the root pointer and the new element to be inserted. It's purpose
  is to add a new element to the BST while ensuring that the tree 
  remains a valid Binary Search Tree.                             ***
*** INPUT ARGS  : const Element element                           ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST:: insert(const Element element){
    insert(root, element);   //calls the recursive version with the root pointer
}
/********************************************************************
*** FUNCTION    : insert                                          ***
*********************************************************************
*** DESCRIPTION : This recursive function inserts a new element into 
the BST. It compares the element with the current node's element and
 decides whether to move left or right, creating new nodes as needed.
It's purpose is to recursively insert elements into the BST while 
maintaining the BST's ordering properties.                        ***
*** INPUT ARGS  : NodePtr &tree, const Element element            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST :: insert(NodePtr &tree, const Element element){
NodePtr newNode = new(std::nothrow)Node;
    if(newNode != nullptr){
        newNode -> element = element;
        newNode -> left = newNode->right = nullptr;
        if(tree == nullptr){
            tree = newNode;
        }
        else if(tree -> element > element){
            insert(tree->left, element);
        }
        else if(tree -> element < element){
            insert(tree->right, element);
        }

        }
    else {
        cout<< "Memory allocation failed" << endl;
    }


}
/********************************************************************
*** FUNCTION    : search                                          ***
*********************************************************************
*** DESCRIPTION : This function initiates a search for a specific 
element in the BST. It calls the recursive version of search with 
the root pointer and the element to be searched for. And it's 
purpose is to initiate the search process in the BST and provide
access to the result of the search.
*** INPUT ARGS  : const Element element                           ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
NodePtr BST::search(const Element element)const{
    return search(root, element);
}
/********************************************************************
*** FUNCTION    : search                                          ***
*********************************************************************
*** DESCRIPTION : This recursive function searches for a specific 
element in the BST. It compares the target element with the current
node's element and recursively navigates left or right depending 
on the comparison. The purpose of this functions is to find a 
specific element within the BST and return a pointer to the node
containing that element. 
*** INPUT ARGS  : const NodePtr tree, const Element element       ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/

NodePtr BST :: search(const NodePtr tree, const Element element) const
{
        if(tree == nullptr){
            return nullptr;
        }
        else if(tree->element == element){
            return tree;
        }
        else if(element < tree->element){
            return search(tree->left, element);
        }
        else{
            return search(tree->right, element);
        }
}
/********************************************************************
*** FUNCTION    : inorderView                                     ***
*********************************************************************
*** DESCRIPTION : exportable function of BST to view the elements in
order of go left, view, then go right. This function calls the recursive version
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST:: inorderView()const
{
    inorderView(root);
}
/********************************************************************
*** FUNCTION    : inorderView                                     ***
*********************************************************************
*** DESCRIPTION : This is the recursive version of viewing in order.
This function provides key values in ascending order (sorted order).
the pattern is go left, view, then go right.                      ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::inorderView(const NodePtr tree) const                        //L V R
{
    if (tree == nullptr) {
        return;  
    } else {
        if (tree == root) {
            cout << "BEGIN -> ";
        }
        inorderView(tree->left);
        cout << tree->element << " -> ";
        inorderView(tree->right);
        if (tree == root) {
            cout << "END" << endl;
        }
    }
}
/********************************************************************
*** FUNCTION    : preorderView                                    ***
*********************************************************************
*** DESCRIPTION : exportable function of BST to view the elements in
order of view, go left, then go right. This function calls the recursive version  
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST:: preorderView()const
{
    preorderView(root);
}
/********************************************************************
*** FUNCTION    : preorderView                                    ***
*********************************************************************
*** DESCRIPTION : Recursive version of the preorder view function
Provides key values in order so that the tree can be rebuilt.
The order of the key values is the root node followed by the left subtree
followed by the right subtree. This form of traversal is often used when copying a tree
                                                 ***
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::preorderView(const NodePtr tree)const               //V L R
{
    
   if (tree == nullptr)
   {
    return;
   }
   if(tree == root)
   {
    cout << "BEGIN -> ";
    cout<<tree->element<<" -> ";
    preorderView(tree->left);
    preorderView(tree->right);
    cout<< "END" <<endl;
   }
    
}
/********************************************************************
*** FUNCTION    : postorderView                                   ***
*********************************************************************
*** DESCRIPTION : exportable function of BST to view the elements in
order of go left, go right, then view. This function calls the recursive version
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST:: postorderView()const
{
    postorderView(root);
}
/********************************************************************
*** FUNCTION    : postorderView                                          ***
*********************************************************************
*** DESCRIPTION : Handles the recursion for the postorder function.
Provides key values in order from the bottom of the tree to the top of the tree
The order of the key values is the left subtree followed by the right subtree
followed by the root node. This form of traversal is often used when destroying a tree***
*** INPUT ARGS  : const NodePtr tree                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::postorderView(const NodePtr tree)const                //L R V
{
    
    if(tree==nullptr){
        return;
    }
    else
    {
        if(tree==root){
        cout<<"BEGIN -> ";
        }
        postorderView(tree->left);
        postorderView(tree->right);
        cout<<tree->element<<" -> ";
        if(tree==root){
        cout<<"END"<<endl;
        }
    }
    
}
/********************************************************************
*** FUNCTION    : remove                                          ***
*********************************************************************
*** DESCRIPTION : This function initiates a search for a specific element in the BST.
 It calls the recursive version of remove with the root pointer and the element to be removed.
And it's purpose is to initiate the remove process in the BST and provide access to the result.***
*** INPUT ARGS  : const ELement element                           ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::remove(const Element element)
{
    remove(root,element);
}
/********************************************************************
*** FUNCTION    : remove                                          ***
*********************************************************************
*** DESCRIPTION : This function recursively looks for the element to bbe removed
If the root is NULL returns Error message. If the element is less goes to the left, if larger goes to the right and when
found calls the removeNOde function to remove the element by passing the pointer.
*** INPUT ARGS  : none                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::remove(NodePtr &tree, const Element element)
{
    if(tree == nullptr)                          //1, empty tree element not found
    {
        cout<<"Element not found"<<endl;
        return;
    }
    if(element == tree->element)               //2, element found call removeNode to remove it
    {
        removeNode(tree);
    }
    else if(element < tree->element)          //3, element less than the current tree element 
    {
        remove(tree->left ,element);
    }
    else                                      //4, element greater than the current tree element 
    {
        remove(tree->right, element);
    }

}
/********************************************************************
*** FUNCTION    : removeNode                                      ***
*********************************************************************
*** DESCRIPTION : This recursion of remove goes through the four different scenarios
that are neede to be considered. Unlike the other fuctions deletions do
not always occure at the bottom or does not always target the leaf nodes.
This function return null if tree is empty. If 0 subtrees delete the 
parent node and set the pointer to the parent node to NULL. Else if 1 subtree
Move the pointer to the parent node to the existing child node and delete the parent node.
And if the element to be removed have 2 subtrees, Find the largest node value in the left subtree
Copy the largest node value(s) into the parent node, move the pointer to the largest left
and finally delete the or largest node. Calls the 'findMAxNode' function to do that last step. 
*** INPUT ARGS  : NodePtr &tree                                            ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST:: removeNode(NodePtr &tree)
{
    if(tree->left == nullptr && tree->right == nullptr)      //1, if no child node delete it and set it to null
    {
        delete tree;
        tree = nullptr;
    }
    else if(tree->left != nullptr && tree->right == nullptr)     //2, left child only or empty right
    {
        NodePtr temp = tree;
        tree = tree->left;
        delete temp;
    }
    else if(tree->right != nullptr && tree->left == nullptr)       //3, right child only or empty left
    {
        NodePtr temp = tree;
        tree = tree->right;
        delete temp;
    }
    else{                                                //4, two childeren
    NodePtr temp = nullptr;
    findMaxNode(tree->left, temp);
    tree->element = temp->element;
    remove(temp->element);
}
}
/********************************************************************
*** FUNCTION    : findMaxNode                                     ***
*********************************************************************
*** DESCRIPTION : Finds the maximum node in the left              ***
*** INPUT ARGS  : NodePtr &tree, NodePtr &temp                    ***
*** OUTPUT ARGS : none                                            ***
*** IN/OUT ARGS : none                                            ***
*** RETURN      : none                                            ***
********************************************************************/
void BST::findMaxNode(NodePtr &tree, NodePtr &temp) {
   if(tree -> right == nullptr){
    temp = tree;
    tree = tree -> left;
   }
   else{
    return findMaxNode(tree->right, temp);
   }
}