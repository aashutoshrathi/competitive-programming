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

Node* rotate(Node* head, int k) {
    if(head == NULL || k == 0) {
        return head;
    }

    Node* temp = head;

    int count = 1;
    
    while(k > count && temp!=NULL) {
        temp = temp->next;
        count++;
    }

    if(temp == NULL) {
        return head;
    }
    
    Node* kN = temp;
    
    while(temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = head;

    head = kN->next;
    
    kN->next = NULL;
    
    return head;
}