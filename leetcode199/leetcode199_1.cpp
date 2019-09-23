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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        
        if (root)
            dfs(root, 1, output);
        
        return output;
    }
    
    void dfs(TreeNode* current, int level, vector<int>& output) {
        if (output.size() < level)
            output.push_back(current->val);
        
        if (current->right)
            dfs(current->right, level + 1, output);
        if (current->left)
            dfs(current->left, level + 1, output);
    }
};

// Runtime: 4 ms, faster than 72.04% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Binary Tree Right Side View.
// time complexity: O(n)
// space complexity: O(n)