#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node *removeDuplicates(Node *root) {
    Node* temp = root;
    while(temp && temp->next) {
        if(temp->next->data == temp->data) {
            temp->next = temp->next->next;
        } else {
            temp = temp->next;
        }
    }
    return root;
}

