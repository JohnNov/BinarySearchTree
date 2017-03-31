#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Node{
    public:

    Node(){
    }
    Node(int someNum){
        data = someNum;
    }
    int data;
    Node *right;
    Node *left;
};

class BinarySearchTree{
    public:

    Node *root = new Node();

    BinarySearchTree(int rootValue);
    void insertNode(Node *aNode, int nodeValue);
    void destroy(Node *aNode);
    void readTree(Node *aNode);

};

BinarySearchTree::BinarySearchTree(int rootValue){
    if(root != NULL){       ///Set up root if it doesn't exist
        root->data = rootValue;
        root->left = NULL;
        root->right = NULL;
        }
                            ///Otherwise we don't do anything so no harm done if called again.
}

void BinarySearchTree::insertNode(Node *aNode, int nodeValue){
    if(nodeValue<(aNode->data)&&aNode->left==NULL){   ///If it's less than and left child doesn't exist
        Node *newNode = new Node(nodeValue);         ///Create a new node with that value
        aNode->left = newNode;
        }
    else if(nodeValue<(aNode->data)&&aNode->left!=NULL) ///If it's less than and left child DOES exist
        {
        insertNode(aNode->left, nodeValue);     ///Recursive call
        }
    else if(nodeValue>=(aNode->data)&&aNode->right==NULL){
        Node *newNode = new Node(nodeValue);
        aNode->right = newNode;
        }
    else{
        insertNode(aNode->right, nodeValue);    ///Recursive call
    }
}

void BinarySearchTree::destroy(Node *aNode){    ///To free up memory

    if(aNode!= NULL){
        destroy(aNode->left);
        destroy(aNode->right);
        delete aNode;
    }
}

void BinarySearchTree::readTree(Node *aNode){       ///Recurssively go through tree
                                                    ///In order of lowest to highest
    if(aNode->left!= NULL)
        readTree(aNode->left);

    cout<<"This nodes data is "<<aNode->data<<endl;

    if(aNode->right!= NULL)
        readTree(aNode->right);
}


int main()
{

    BinarySearchTree bst(10);       ///Provide a root value of 10

    bst.insertNode(bst.root, 5);    ///Add some nodes
    bst.insertNode(bst.root, 1);
    bst.insertNode(bst.root, 7);
    bst.insertNode(bst.root, 12);
    bst.insertNode(bst.root, 11);
    bst.insertNode(bst.root, 13);

    bst.readTree(bst.root);         ///Read the tree

    bst.destroy(bst.root);          ///Free the memory

    return 0;
}


