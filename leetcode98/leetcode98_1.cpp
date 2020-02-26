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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> st;
        long long inorder = (long long)INT_MIN - 1;
        
        while (!st.empty() || root) {
            while (root) {
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            
            // If next element in inorder traversal
            // is smaller than the previous one
            // that's not BST
            if (root->val <= inorder)
                return false;
            
            inorder = root->val;
            root = root->right;
        }
        
        return true;
    }
};


// Runtime: 16 ms, faster than 64.85% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 20.6 MB, less than 87.50% of C++ online submissions for Validate Binary Search Tree.
// time complexity: O(n)
// space complexity: O(n)