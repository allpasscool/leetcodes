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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (root->left) root->left = removeLeafNodes(root->left, target);
        if (root->right) root->right = removeLeafNodes(root->right, target);
        return root->left == root->right && root->val == target ? NULL : root;
    }
};


// Runtime: 20 ms, faster than 84.08% of C++ online submissions for Delete Leaves With a Given Value.
// Memory Usage: 21.6 MB, less than 100.00% of C++ online submissions for Delete Leaves With a Given Value.
// time complexity: O(n)
// space complexity: O(1)
// https://leetcode.com/problems/delete-leaves-with-a-given-value/discuss/484264/JavaC%2B%2BPython-Recursion-Solution