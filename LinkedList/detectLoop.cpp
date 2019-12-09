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

int detectloop(Node *head) {
    Node* fp = head;
    Node* sp = head;
    while(fp && sp && fp->next != NULL) {
        sp = sp->next;
        fp = fp->next->next;
        if(fp == sp) {
            return 1;
        }
    }
    return 0;
}