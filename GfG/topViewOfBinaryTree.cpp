#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    // one can always add height elem here in Node
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// function should print the topView of the binary tree
void topView(struct Node *root) {
    int h = 0;
    map<int, int> m;
    if(!root) {
        return;
    }
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, h));
    while(q.size()) {
        pair<Node*, int> x = q.front();
        q.pop();
        
        Node* y = x.first;
        int k = x.second;

        if(m.count(k) == 0) // If this line is removed its bottom view
            m[k] = y->data;
        
        if(y->left) {
            q.push(make_pair(y->left, k-1));
        }
        if(y->right) {
            q.push(make_pair(y->right, k+1));
        }
    }
    for(auto i:m) {
        cout << i.second << " ";
    }
}
