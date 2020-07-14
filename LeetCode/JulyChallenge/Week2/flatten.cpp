/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) 
            return head;
        
        Node* it = head;
        while(it) {
            if(it->child) {
                Node* tmp = it->next;
                Node* child = flatten(it->child);
                it->child = nullptr;
                it->next = child;
                child->prev = it;
                
                Node* lastNode = child;
                while(lastNode->next) 
                    lastNode = lastNode->next;
                
                lastNode->next = tmp;
                
                if(tmp) 
                    tmp->prev = lastNode;
            }
            
            it = it->next;
        }
        return head;
    }
};
