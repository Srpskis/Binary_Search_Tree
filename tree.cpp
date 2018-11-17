// Ana Taylor
// tree.cpp
// Implementation for p3


#include "tree.h"
#include <iostream>
using namespace std;



// Constructor
BinaryTree::BinaryTree() {

    root = nullptr;

}


// Copy Constructor
BinaryTree::BinaryTree(const BinaryTree &copy) {

    if (copy.root == nullptr) {

        root = nullptr;

    } else {

        root = makeCopy(copy.root);
    }


}


// Overloaded Assignment Operator
BinaryTree &BinaryTree::operator=(const BinaryTree &rhs) {

    if (this != &rhs) {

        destroyTree(root);
        root = makeCopy(rhs.root);

    }
    return *this;

}


// Helper method for the Copy Constructor and O.A.O
BinaryTree:: Node *BinaryTree::makeCopy(Node *root) {

    if (root == nullptr) {

        return nullptr;

    } else {

        Node *temp = new Node;
        temp->number = root->number;
        temp->left = makeCopy(root->left);
        temp->right = makeCopy(root->right);
        return temp;
    }
}


// Destructor
BinaryTree::~BinaryTree() {

    destroyTree(root);

}


// Helper method called by destructor
void BinaryTree::destroyTree(Node *&root) {

    if (root != nullptr) {

        destroyTree(root->left);
        destroyTree(root->right);
        delete root;
        root = nullptr;

    }
}


// public insert method
void BinaryTree::insert(int num) {

    Node *newNode = new Node;
    newNode->number = num;
    newNode->left = nullptr;
    newNode->right = nullptr;

    insert(root, newNode);

}


// private helper method for insertion
void BinaryTree::insert(Node *&root, Node *&newNode) {

    if (root == nullptr) {

        root = newNode;

    } else if (newNode->number < root->number) {

        insert(root->left, newNode);

    } else if (newNode->number > root->number) {

        insert(root->right, newNode);

    } else {

        return;
    }

}


// public preOrder method
void BinaryTree::preOrder() {

    preOrder(root);

}


// private preOrder helper method
void BinaryTree::preOrder(Node *root) {

    if (root != nullptr) {

        cout << root->number << " ";
        preOrder(root->left);
        preOrder(root->right);


    }

}


// public findKey method
bool BinaryTree::findKey(int num) {

    Node *nodePtr;
    nodePtr = root;


    while (nodePtr != nullptr) {

        if (nodePtr->number == num) {

            return true;

        } else if (num < nodePtr->number) {

            nodePtr = nodePtr->left;

        } else {

            nodePtr = nodePtr->right;

        }
    }
    return false;


}


// public minKey method
int BinaryTree::minKey() {

    Node *current = root;

    while (current->left != nullptr) {

        current = current->left;

    }
    return current->number;

}


// public maxKey method
int BinaryTree::maxKey() {

    Node *current = root;

    while (current->right != nullptr) {

        current = current->right;

    }
    return current->number;

}


// public height method
int  BinaryTree::height() {

    return findHeight(root);

}


// private findHeight method
int BinaryTree::findHeight(Node *root) {

    if (root == nullptr) {

        return 0;

    } else {

        int leftHeight = findHeight(root->left);
        int rightHeight = findHeight(root->right);

        if (leftHeight > rightHeight) {

            return 1 + leftHeight;

        } else {

            return 1 + rightHeight;
        }
    }
}



// public non-recursive inOrder method
void BinaryTree::inOrder() {

    stack<Node*> stack;
    Node *current = root;

    while (current != nullptr || !stack.empty()) {
        if (current != nullptr) {
            stack.push(current);
            current = current->left;

        } else {

            current = stack.top();
            stack.pop();
            cout << current->number << " ";
            current = current->right;
        }
    }
}


// public method for single node deletion
void BinaryTree::remove(int num) {

    deleteNode(root, num);

}


// private helper method for locating the parent of the node to be deleted
void BinaryTree::deleteNode(Node *&root, int num) {

    if (num < root->number) {

        deleteNode(root->left, num);

    } else if (num > root->number) {

        deleteNode(root->right, num);

    } else {

        deletion(root);
    }
}


// private helper methid to delete the individual nodes
void BinaryTree::deletion(Node *&root) {

    Node *temp;
    temp = nullptr;

    // warning if the tree is empty
    if (root == nullptr) {

        cout << "Cannot delete empty node" << endl;

    // if node has one child
    } else if (root->right == nullptr) {

        temp = root;
        root = root->left;
        delete temp;

    } else if (root->left == nullptr) {

        temp = root;
        root = root->right;
        delete temp;

    // if node has two children
    } else {

        temp = root->right;
        while (temp ->left != nullptr) {
            temp = temp->left;

        }
        temp->left = root->left;
        temp = root;
        root = root->right;
        delete temp;

    }
}


int BinaryTree::countNodes() {

    return countNodes(root);
}


int BinaryTree::countNodes(Node *root) {

    int count = 1;

    if (root == nullptr) {

        return 0;

    } else {

        count = count + countNodes(root->left);
        count = count + countNodes(root->right);

    }
    return count;
}

int BinaryTree::countFullNodes() {

    return countFullNodes(root);

}

int BinaryTree::countFullNodes(Node *root) {

    if (root == nullptr) {

        return 0;
    }

    int count = 0;
    if (root->left != nullptr && root->right != nullptr) {

        count++;
    }
    count = count + (countFullNodes(root->left) + countFullNodes(root->right));
    return count;

}

int BinaryTree::countLeafNodes() {

    return countLeafNodes(root);

}

int BinaryTree::countLeafNodes(Node *root) {

    if (root == nullptr) {

        return 0;

    }

    if (root->left == nullptr && root->right ==  nullptr) {

        return 1;

    } else {

        int count = 0;
        count = countLeafNodes(root->left) + countLeafNodes(root->right);
        return count;

    }

}

void BinaryTree::levelOrderTraversal() {

    queue<Node *> queue;
    Node *current;

    queue.push(root);
    queue.push(nullptr);

    while (queue.size() > 1) {

        current = queue.front();
        queue.pop();

        if (current == nullptr) {

            queue.push(nullptr);
            cout << " ";

        } else {

            if (current->left != nullptr) {

                queue.push(current->left);

            }
            if (current->right != nullptr) {

                queue.push(current->right);

            }
            cout << current->number << " ";

        }
    }



}