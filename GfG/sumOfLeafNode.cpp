#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
using namespace std;

struct Node {
	int data;
	Node *left, *right;
};

int sumLeaf(Node* root) {
    if(!root)
        return 0;
    if(!(root->left) && !(root->right))
        return root->data;
    return sumLeaf(root->left) + sumLeaf(root->right);
}