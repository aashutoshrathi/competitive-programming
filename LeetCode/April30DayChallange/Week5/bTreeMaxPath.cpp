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
    int res;
    int f(TreeNode* root) {
        if(root == NULL) {
            return 0;
        }
        int l = f(root->left);
        int r = f(root->right);
        res = max(res, root->val+l+r);
        return max(0, root->val + max(l,r));
    }
    
    int maxPathSum(TreeNode* root) {
        res = INT_MIN;
        f(root);
        return res;
    }
};