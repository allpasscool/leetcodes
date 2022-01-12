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
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);

        if (val > root->val)
            root->right = insertIntoBST(root->right, val);
        else
            root->left = insertIntoBST(root->left, val);

        return root;
    }
};

// Runtime: 64 ms, faster than 99.96% of C++ online submissions for Insert into a Binary Search Tree.
// Memory Usage: 56.9 MB, less than 49.59% of C++ online submissions for Insert into a Binary Search Tree.
// time complexity: O(H)
// space complexity: O(H)