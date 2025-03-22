#include "sort_search.h"

struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int x)
	{
		data = x;
		left = right = NULL;
	}
};
void makeNode(Node* root, int u, int v, char c)
{
	if (c == 'L') root->left = new Node(v);
	else root->right = new Node(v);
}
void insert(Node* root, int u, int v, int c)
{
	if (root == NULL) return;
	if (root->data == u) makeNode(root, u, v, c);
	else
	{
		insert(root->left, u, v, c);
		insert(root->right, u, v, c);
	}
}