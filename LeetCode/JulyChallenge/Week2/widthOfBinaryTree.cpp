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
    unordered_map<int, int> m;
	int res = 0;
    void dfs(TreeNode* node, int level, int val) {
		if (!node)
		    return;

		if (m.find(level) == m.end())
			m[level] = val;

		res = max(res, val - m[level] + 1);

		dfs(node->left, level + 1, 2 * (long)val);
		dfs(node->right, level + 1, 2 * (long)val + 1);
	}
    
    int widthOfBinaryTree(TreeNode* root) {
		dfs(root, 0, 0);
		return res;
    }
};
