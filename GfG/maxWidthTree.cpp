#include <iostream>
#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;

struct Node {
	int key;
	struct Node *left, *right;
};


int getMaxWidth(Node* root) {
   int count;
   int res = 0;
   queue<Node*> q;
   q.push(root);
   while(!q.empty()) {
       count = q.size();
       res = max(res, count);
       while(count--) {
           Node* t = q.front();
           q.pop();
           if(t->left) {
               q.push(t->left);
           }
           if(t->right) {
               q.push(t->right);
           }
       }
   }
   return res;
}