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
    unordered_map<int, pair<int, int>> m;
    int doStuff(TreeNode* root, int parent, int depth) {
        if(!root) {
            return -1;
        }
        
        m[root->val] = {parent, depth};
        
        if(root->left) {
            doStuff(root->left, root->val, depth+1);
        }
        
        if(root->right) {
            doStuff(root->right, root->val, depth+1);
        }
        return -1;
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        doStuff(root, -1, 0);
        // for(auto i: m) {
        //     cout << i.first << "-> {" << i.second.first << ", " << i.second.second  << "}" << endl;
        // }
        return (m[x].second == m[y].second) && (m[x].first != m[y].first);
    }
};