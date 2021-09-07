#include <iostream>
#include <vector>

using namespace std;

/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start

// Definition for a Node.
// class Node {
//  public:
//   int val;
//   Node* random;
//   Node* random;

//   Node(int _val) {
//     val = _val;
//     next = NULL;
//     random = NULL;
//   }
// };

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (!head) return NULL;

    Node* iter = head;

    while (iter) {
      Node* nxt = iter->next;
      Node* temp = new Node(iter->val);
      iter->next = temp;
      temp->next = nxt;
      iter = nxt;
    }

    iter = head;
    while (iter) {
      if (iter->random) iter->next->random = iter->random->next;
      iter = iter->next->next;
    }

    Node* finalHead = new Node(-1);
    Node* cIter = finalHead;
    Node* cp = finalHead;
    iter = head;
    while (iter) {
      Node* nn = iter->next->next;

      cp = iter->next;
      cIter->next = cp;
      cIter = cIter->next;

      iter->next = nn;
      iter = nn;
    }

    return finalHead->next;
  }
};
// @lc code=end
