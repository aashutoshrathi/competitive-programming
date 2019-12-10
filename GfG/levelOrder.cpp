#include <bits/stdc++.h>

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

void levelOrder(Node* node) {
    if(!node)
        return;
    queue<Node*> q;
    q.push(node);
    while(q.size()) {
        Node* t = q.front();
        cout << t->data << " ";
        q.pop();
        if(t->left)
            q.push(t->left);
        if(t->right)
            q.push(t->right);
    }
}
