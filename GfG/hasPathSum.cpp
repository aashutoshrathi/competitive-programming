#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* left, * right;
}; 

bool hasPathSum(Node *node, int sum) {
    if(!node) {
        return (sum == 0);
    }
    bool ans = 0;
    int s = sum - node->data;
    if(s == 0 && !node->left && !node->right)
        return 1;
    if(node->left)
        ans = ans || hasPathSum(node->left, s);
    if(node->right)
        ans = ans || hasPathSum(node->right,s );
    return ans;
}