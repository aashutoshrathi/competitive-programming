#include <bits/stdc++.h> 	// Apne aap me sab kuch hai isme 
#include <stdio.h>

using namespace std;

struct node {
    int data;
    struct node *next;
    node(int x) {
        data = x;
        next = NULL;
    }
};


struct node *reverse (struct node *head, int k) { 
    node* curr = head;
    node* next = NULL;
    node* prev = NULL;
    int c = 0;

    while(curr != NULL && c < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        c++;
    }
    
    if(next)
        head->next = reverse(next, k);

    return prev;
}