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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};
// Runtime: 16 ms, faster than 23.06% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 19.3 MB, less than 79.12% of C++ online submissions for Maximum Depth of Binary Tree.
// time complexity: O(n)
// space complexity: O(log n)