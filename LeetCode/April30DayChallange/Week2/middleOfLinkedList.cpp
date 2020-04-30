/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* cp = head;
        while(cp->next) {
            cp = cp->next;
            if(cp->next) {
                cp = cp->next;
            }
            head = head->next;
        }
        return head;
    }
};