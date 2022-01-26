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
    TreeNode *findNearestRightNode(TreeNode *root, TreeNode *u)
    {
        queue<TreeNode *> q;
        q.push(root);

        while (!q.empty())
        {
            int num = q.size();

            for (; num > 0; num--)
            {
                TreeNode *cur = q.front();
                q.pop();

                // target found
                if (cur == u)
                {
                    if (num == 1)
                        return NULL;
                    else
                        return q.front();
                }

                // push next layer
                if (cur->left)
                    q.push(cur->left);
                if (cur->right)
                    q.push(cur->right);
            }
        }

        return NULL;
    }
};

// Runtime: 217 ms, faster than 61.64% of C++ online submissions for Find Nearest Right Node in Binary Tree.
// Memory Usage: 86.5 MB, less than 49.92% of C++ online submissions for Find Nearest Right Node in Binary Tree.
// time complexity: O(n)
// space complexity: O(n)