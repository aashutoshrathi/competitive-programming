/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
 */

// @lc code=start
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dh = new ListNode(0);
        ListNode* l3 = dh;
        int p = l1->val, q= l2->val;
        while(l1 || l2) {
            p = l1 ? l1->val : 0;
            q = l2 ? l2->val : 0;
            int sum = p + q + carry;
            carry = (sum)/10;
            l3->next = new ListNode(sum%10);
            l3 = l3->next;
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
        }
        if(carry > 0)
            l3->next = new ListNode(carry);
        return dh->next;
    }
};
// @lc code=end

