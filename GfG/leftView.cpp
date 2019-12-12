#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};


void leftViewUtil(Node *node, int level, int *ml) {
    if(!node)
        return;
    if(level > *ml) {
        *ml = level;
        cout << node->data << " ";
    }
    leftViewUtil(node->left, level+1, ml);
    leftViewUtil(node->right, level+1, ml);
}

// A wrapper over leftViewUtil()
void leftView(Node *root) {
    int ml = 0;
    leftViewUtil(root, 1, &ml);
}
