/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    int getHeight(TreeNode* root) {
        if(!root) {
            return 0;
        }
        int l = getHeight(root->left); 
        int r = getHeight(root->right); 
        ans = max(ans, l + r + 1); 

        return 1 + max(l, r); 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) {
            return 0;
        }
        getHeight(root);
        return ans - 1;
    }
};