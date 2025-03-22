#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data)
{
    Node* newNode= new Node();
    newNode->data= data;
    newNode->left=NULL;
    newNode->right=NULL;
    return newNode;
}
void Preorder(Node*root)
{
    if(root==NULL) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);
}

