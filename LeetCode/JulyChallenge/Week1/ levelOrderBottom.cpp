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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root)
            return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            int width = q.size();
            vector<int> temp;
            
            while(width--) {
                TreeNode* top = q.front();
                
                q.pop();
                
                if(top->left)
                    q.push(top->left);
                if(top->right)
                    q.push(top->right);
                
                temp.push_back(top->val);
            }
            
            res.insert(res.begin(), temp);
        }
        return res;
    }
};