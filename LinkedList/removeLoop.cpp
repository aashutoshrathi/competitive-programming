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

void removeTheLoop(Node *head) {
    if (head == NULL || head->next == NULL) 
        return; 
    Node* s = head;
    Node* f = head;
    while(s && f && f->next) {
        s = s->next;
        f = f->next->next;
        if(s == f) {
            break;
        }
    }
    // i.e. first check if there is loop, if found.
    // then move the slow pointer to head and run it with fast ptr.

    if(s==f) {
        s = head;
        while(s->next!=f->next) {
            s = s->next;
            f = f->next;
        }
        f->next = NULL;
    }
}