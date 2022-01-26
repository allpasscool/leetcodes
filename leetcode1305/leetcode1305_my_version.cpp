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
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2)
    {
        // set<int> ans;
        vector<int> ans;

        traverseTree(root1, ans);
        traverseTree(root2, ans);

        sort(begin(ans), end(ans));

        return ans;
    }

    void traverseTree(TreeNode *root, vector<int> &ans)
    {
        queue<TreeNode *> q;

        // traverse root1
        if (root)
            q.push(root);
        while (!q.empty())
        {
            TreeNode *cur = q.front();
            q.pop();
            ans.push_back(cur->val);
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
    }
};

// Runtime: 250 ms, faster than 23.47% of C++ online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 86.4 MB, less than 38.94% of C++ online submissions for All Elements in Two Binary Search Trees.
// time complexity: O(n log n)
// space complexity: O(n)