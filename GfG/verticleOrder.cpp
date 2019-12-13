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

void verticalOrder(Node *root) {
    if(!root)
        return;

    int h = 0;
    map<int, vector<int>> m;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root, h));

    while(q.size()) {
        pair<Node*, int> x = q.front();
        q.pop();
        
        Node* y = x.first;
        int k = x.second;

        m[k].push_back(y->data);
        
        if(y->left)
            q.push(make_pair(y->left, k-1));
        if(y->right)
            q.push(make_pair(y->right, k+1));
    }

    map<int,vector<int>>::iterator it;

    for (it=m.begin(); it!=m.end(); it++)
        for (int i=0; i<it->second.size(); ++i) 
            cout << it->second[i] << " ";
}
