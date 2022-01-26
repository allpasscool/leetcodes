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
        vector<int> ans;

        traverseTree(root1, ans);
        int n1 = ans.size();

        traverseTree(root2, ans);
        int n = ans.size();
        int p1 = 0, p2 = n1;

        vector<int> ansArr(n);

        for (int i = 0; i < n; i++)
        {
            if (p1 < n1 && (p2 == n || ans[p1] <= ans[p2]))
            {
                ansArr[i] = ans[p1];
                p1++;
            }
            else
            {
                ansArr[i] = ans[p2];
                p2++;
            }
        }

        return ansArr;
    }

    void traverseTree(TreeNode *root, vector<int> &ans)
    {
        if (!root)
            return;

        // inorder
        if (root->left)
            traverseTree(root->left, ans);
        ans.push_back(root->val);
        if (root->right)
            traverseTree(root->right, ans);
    }
};

// Runtime: 284 ms, faster than 12.74% of C++ online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 85.3 MB, less than 48.31% of C++ online submissions for All Elements in Two Binary Search Trees.
// time complexity: O(n)
// space complexity: O(n)