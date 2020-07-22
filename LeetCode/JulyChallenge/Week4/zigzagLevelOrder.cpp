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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<pair<TreeNode*, int>> q;
        if(root)
            q.push({root, 0});
        while(!q.empty()) {
            auto [node, lvl] = q.front();
            q.pop();
            if(node) {
                if(res.size() <= lvl)
                    res.push_back({ node->val });
                else
                    res[lvl].insert( lvl%2 ? res[lvl].begin() : res[lvl].end() ,node->val);
                
                q.push({ node->left, lvl+1 });
                q.push({ node->right, lvl+1 });
            }
            
        }
        return res;
    }
};
