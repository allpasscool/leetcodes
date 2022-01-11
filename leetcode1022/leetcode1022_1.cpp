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
    int sumRootToLeaf(TreeNode *root, int val = 0)
    {
        if (!root)
            return 0;
        val = (val * 2 + root->val);
        return root->left == root->right ? val : sumRootToLeaf(root->left, val) + sumRootToLeaf(root->right, val);
    }
};

// Runtime: 8 ms, faster than 53.68% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
// Memory Usage: 16.7 MB, less than 43.41% of C++ online submissions for Sum of Root To Leaf Binary Numbers.
// time complexity: O(n)
// space complexity: O(H)
// https://leetcode.com/problems/sum-of-root-to-leaf-binary-numbers/discuss/270025/JavaC%2B%2BPython-Recursive-Solution