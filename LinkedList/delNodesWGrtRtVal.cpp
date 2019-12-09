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

Node *reverse(Node *head) {
    Node* temp = head;
    Node* next = NULL;
    Node* prev = NULL;
    while(temp) {
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    return prev;
}

Node *compute(Node *head){
    Node* rev = reverse(head); // reverse
    
    // keep max till now
    // space can also be freed
    Node* tmp = rev;
    int m = tmp->data;
    while(tmp->next) {
        if(tmp->next->data < m)
            tmp->next = tmp->next->next;
        else {
            m = tmp->next->data;
            tmp = tmp->next;
        }
    }

    Node* res = reverse(rev); // reverse
    return res;
}