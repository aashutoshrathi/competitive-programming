/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool f(TreeNode* root, vector<int>& arr, int i) {  
        int n = arr.size();
        if (root == NULL || i == n) 
            return false; 

       if ((root->left == NULL && root->right == NULL) && 
           (root->val == arr[i]) && (i == n-1)) 
                return true; 

       return ((i < n) && (root->val == arr[i]) && 
                  (f(root->left, arr,  i+1) || 
                   f(root->right, arr, i+1) )); 
    } 
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        return f(root, arr, 0);
    }
};