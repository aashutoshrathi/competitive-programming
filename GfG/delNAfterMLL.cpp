#include <iostream>
using namespace std;


struct Node {
    int data;
    Node* next;
}; 


void linkdelete(struct Node  *head, int M, int N) {
    int count = 1;
    if(!head)
        return;
    Node* t = head;
    while(count < M && t) {
        t = t->next;
        count++;
    }
    if(!t)
        return;
    count = 0;
    Node* u = t;
    while(count <= N && u) {
        u = u->next;
        count++;
    }
    t->next = u;
    linkdelete(u, M, N);
    return;
}