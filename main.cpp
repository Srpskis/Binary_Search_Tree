#include <iostream>
#include "tree.h"
#include "tree.cpp"


int main() {

    cout << endl << endl << endl << endl;

    cout << "---------- BEGINNING OF TEST ----------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Press ENTER until the end to reveal tests..." << endl;

    cout << endl;
    cin.get();

    BinaryTree tree;

    cout << "------- TESTING insert FUNCTION -------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Inserting values in tree..." << endl;
    int nodeValues[] = {15, 10, 20, 5, 12, 17, 25, 3, 7, 11, 13, 16, 19, 22, 27, 1, 4, 6, 9, 14, 18, 21, 23, 26, 28};

    for(int i = 0; i < 25; i++) {
        cout << "Inserting value " << i << " ..."<< endl;
        tree.insert(nodeValues[i]);
    }

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING preOrder FUNCTION ------" << endl;
    cout << "---------------------------------------" << endl;
    cout << "Displaying the values preOrder..." << endl;
    tree.preOrder();

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING inOrder FUNCTION ------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Displaying the values inOrder..." << endl;
    tree.inOrder();

    cout << endl << endl;
    cin.get();

    cout << "-- TESTING INSERTION OF DUPLICATE VALUES --" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Attempting to insert some duplicate values..." << endl;
    cout << "Insert function prevents this." << endl;
    cout << "Inserting duplicate value 15 ..." << endl;
    tree.insert(15);
    cout << "Inserting duplicate value 7 ..." << endl;
    tree.insert(7);
    cout << "Inserting duplicate value 6 ..." << endl;
    tree. insert(6);

    cout << endl;

    cout << "Displaying inOrder again after attempting to insert the duplicate values..." << endl;
    tree.inOrder();
    cout << endl;
    cout << "Inserting duplicate values failed. No duplicates in the tree. " << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING findKey FUNCTION ------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Searching for number 5..." << endl;
    if (tree.findKey(5)) {

        cout << "Number 5 is found in the tree." << endl;

    } else {

        cout << "Number 5 is not in the tree." << endl;
    }

    cout << endl;

    cout << "Searching for number 24..." << endl;
    if (tree.findKey(24) == true) {

        cout << "Number 24 is found in the tree." << endl;

    } else {

        cout << "Number 24 is not in the tree." << endl;
    }

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING findMin and findMax FUNCTION ------" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "Searching and displaying the minimum value in the tree..." << endl;
    cout << "Minimum key is: " << tree.minKey() << endl;
    cout << "Searching and displaying the maximum value in the tree..." << endl;
    cout << "Maximum key is: " << tree.maxKey() << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING height FUNCTION ------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Displaying the height of the tree..." << endl;
    cout << "The root of the tree is: " << tree.height() << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING delete FUNCTION ------" << endl;
    cout << "-------------------------------------" << endl;
    cout << "Deleting individual nodes in the tree..." << endl;
    cout << "Deleting number 22..." << endl;
    tree.remove(22);
    cout << "Deleting number 1..." << endl;
    tree.remove(1);
    cout << "Deleting number 28..." << endl;
    tree.remove(28);

    cout << "Now displaying the inOrder to see if the removal is successful..." << endl;
    tree.inOrder();
    cout << endl;
    cout << "Individual nodes deleted successfully." << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING COPY CONSTRUCTOR ------" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Creating second that is a copy of our original tree..." << endl;
    BinaryTree newTree1(tree);
    cout << "Displaying the inOrder for the new tree..." << endl;
    newTree1.inOrder();

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING OVERLOADED ASSIGNMENT OPERATOR ------" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "Creating third tree that is going to be the copy of the second tree... " << endl;
    BinaryTree newTree2;
    newTree2 = newTree1;
    cout << "Displaying the inOrder for the new tree..." << endl;
    newTree2.inOrder();

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING countNodes ------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Counting the nodes in the tree..." << endl;
    cout << "The number of nodes in the tree is " << tree.countNodes() << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING countFullNodes ------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Counting the nodes with two children..." << endl;
    cout << "The number of nodes with two children is " << tree.countFullNodes() << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING countLeafNodes ------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Counting the leaf nodes..." << endl;
    cout << "The number of leaf nodes is " << tree.countLeafNodes() << endl;

    cout << endl << endl;
    cin.get();

    cout << "------ TESTING levelOrderTraversal ------" << endl;
    cout << "--------------------------------" << endl;
    cout << "Level order is: ";
    tree.levelOrderTraversal();

    cout << endl << endl;
    cin.get();

    cout << "-------------- END OF TEST --------------" << endl;
    cout << "-----------------------------------------" << endl;

    return 0;

}