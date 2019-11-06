/*This is a function problem.You only need to complete the function given below*/
/*Structure of the node of the binary tree is as
struct Node
{
	int data;
	Node *left, *right;
};*/
// function should return the sum of all the 
// leaf nodes of the binary tree 
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
using namespace std;

struct Node
{
	int data;
	Node *left, *right;
};

int sumLeaf(Node* root) {
    if(root == NULL) {
        return 0;
    }
    if(root->left == NULL && root->right == NULL) {
        return root->data;
    }
    return sumLeaf(root->left)+sumLeaf(root->right);
}