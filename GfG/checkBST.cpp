#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool isBST(Node* root) {
    return isBSTUtil(root, INT_MIN, INT_MAX);
}

int isBSTUtil(Node* root, int min, int max) {
    if(root == NULL)
        return 1;
    if(root->data < min || root->data > max)
        return 0;
    return (isBSTUtil(root->left, min, root->data - 1) 
    && isBSTUtil(root->right, root->data + 1, max));
}
