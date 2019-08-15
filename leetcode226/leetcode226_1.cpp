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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        
        TreeNode* left = invertTree(root->left);
        TreeNode* right = invertTree(root->right);
        swap(root->left, root->right);
        
        return root;
    }
};
// Runtime: 4 ms, faster than 59.28% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 9.2 MB, less than 85.45% of C++ online submissions for Invert Binary Tree.
// time complexity: O(N)
// space complexity: O(N)