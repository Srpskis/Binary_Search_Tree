// Ana Taylor
// tree.h
// Header file for p3

#ifndef P3_TREE_H
#define P3_TREE_H

#include <queue>;
#include <stack>;


class BinaryTree {

private:

    struct Node {

        int number;
        Node *left;
        Node *right;

    };

    Node *root;

    void insert(Node *&root, Node *&newNode);
    // helper recursive method for inserting nodes
    // pre: tree is empty
    // post: inserting nodes without duplicates
    void preOrder(Node *root);
    // helper recursive method for displaying the values in nodes
    // pre: passing root
    // post: nodes displayed preOrder
    void destroyTree(Node *&root);
    // helper method called by the destructor
    // pre: the tree is not empty
    // post: all nodes are deleted, root set to null
    void deletion(Node *&root);
    // helper method for deleting single nodes
    // pre: tree is not empty
    // post: the node with the value passed is deleted
    void deleteNode(Node *&root, int num);
    // helper method for finding the parent of the node to be deleted
    // pre: the tree is not empty
    // post: finds parent of the node to be deleted
    Node * makeCopy(Node *root);
    // helper method for copy constructor and overloaded a.o.
    // pre: called by the c.c and o.a.o
    // post: copies nodes, returns nodes
    int findHeight(Node *root);
    // helper method for finding the height of the tree
    // pre: tree is not empty
    // post: returns the height of tree
    int countNodes(Node *root);
    // counts all the nodes in the tree
    int countFullNodes(Node *root);
    // count nodes with two children
    int countLeafNodes(Node *root);
    // counts leaf nodes



public:


    BinaryTree();
    // constructor
    BinaryTree(const BinaryTree &);
    // copy constructor
    BinaryTree &operator = (const BinaryTree &rhs);
    // overloaded assignment operator
    ~BinaryTree();
    // destructor

    void insert(int num);
    // method for inserting the values in the tree
    // pre: serves to pass the root to the private recursive function
    // post:
    bool findKey(int num);
    // method to find the key value in the nodes
    // pre: tree is not empty
    // post: returns boolean flag if value found or not
    int minKey();
    // method to find a minimum key in the tree
    // pre:
    // post: returns the minimum value
    int maxKey();
    // method to find a minimum key in the tree
    // pre:
    // post: returns the maximum value
    int height();
    // method to find a height of the tree
    // pre: serves to pass the root to the private insert function
    // post:
    void inOrder();
    // non recursive method to display the ordered values in tree
    // pre: tree is not empty
    // post: displays the ordered values
    void preOrder();
    // method that displays the values in the tree
    // pre: tree is not empty
    // post: passes the root of the tree, displays values
    void remove(int num);
    // pre: passes the number to be deleted to helper function
    // post: helper function finds the parent and forwards to delete function
    int countNodes();
    // counts the number of nodes
    int countFullNodes();
    // count the number of nodes with two children
    int countLeafNodes();
    // count the number of last nodes(leaf nodes)
    void levelOrderTraversal();

};

#endif //P3_TREE_H
