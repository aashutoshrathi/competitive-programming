#include <iostream>
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

Node * lca(Node* root ,int n1 ,int n2 ) {
    if(!root)
        return NULL;
    if(root->data > n1 && root->data > n2) {
        return lca(root->left, n1, n2);
    }
    if(root->data < n1 && root->data < n2) {
        return lca(root->right, n1, n2);
    }
    return root;
}