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
        stack<TreeNode *> stack1, stack2;
        vector<int> output;

        while (root1 || root2 || !stack1.empty() || !stack2.empty())
        {
            // update both stacks
            // by going left till possible
            while (root1)
            {
                stack1.push(root1);
                root1 = root1->left;
            }
            while (root2)
            {
                stack2.push(root2);
                root2 = root2->left;
            }

            // Add the smallest value into output,
            // pop it from the stack,
            // and then do one step right
            if (stack2.empty() || !stack1.empty() && stack1.top()->val <= stack2.top()->val)
            {
                root1 = stack1.top();
                stack1.pop();
                output.push_back(root1->val);
                root1 = root1->right;
            }
            else
            {
                root2 = stack2.top();
                stack2.pop();
                output.push_back(root2->val);
                root2 = root2->right;
            }
        }
        return output;
    }
};

// Runtime: 237 ms, faster than 27.34% of C++ online submissions for All Elements in Two Binary Search Trees.
// Memory Usage: 84.5 MB, less than 67.43% of C++ online submissions for All Elements in Two Binary Search Trees.
// time complexity: O(n)
// space complexity: O(n)