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
    vector<pair<int, int>> v;
    void inorder(TreeNode* root, vector<pair<int, int>>& v, int k) {
        if(!root)
            return;
        
        inorder(root->left, v, k);
        
        if(++v[0].first == k) {
            v[0].second = root->val;
            return;
        }
        
        inorder(root->right, v, k);
        
    }
    
    int kthSmallest(TreeNode* root, int k) {
        v.push_back({0, root->val});
        inorder(root, v, k);
        return v[0].second;
    }
};
