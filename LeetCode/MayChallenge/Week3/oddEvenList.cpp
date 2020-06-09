/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) {
            return NULL;
        }
        ListNode* o = head;
        ListNode* e = head->next;
        ListNode* eHead = e;
        while(e && e->next) {
            o->next = e->next; // skips 1
            o = o->next; // jumps 1
            e->next = o->next; // skips 1
            e = e->next; // jumps 1
        }
        o->next = eHead;
        return head;
    }
};
