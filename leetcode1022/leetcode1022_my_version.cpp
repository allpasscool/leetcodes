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
    int sumRootToLeaf(TreeNode *root)
    {
        int ans = 0;

        if (!root)
            return ans;
        if (!root->left && !root->right)
            ans = root->val;
        if (root->left)
            ans += sumOfPath(root->left, root->val);
        if (root->right)
            ans += sumOfPath(root->right, root->val);

        return ans;
    }

    int sumOfPath(TreeNode *root, int count)
    {
        count = count * 2 + root->val;
        int sumOfChild = 0;
        if (root->left)
            sumOfChild += sumOfPath(root->left, count);
        if (root->right)
            sumOfChild += sumOfPath(root->right, count);
        if (!root->left && !root->right)
            sumOfChild = count;

        return sumOfChild;
    }
};

// Runtime: 12 ms, faster than 24.54% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
// Memory Usage: 16.6 MB, less than 72.35% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
// time complexity: O(n)
// space complexity: O(log n)