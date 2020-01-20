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
        if (!root) {
            return root;
        }
        
        bool del = dfs(root, target);
        if (del) {
            root = nullptr;
        }
        
        return root;
    }
    
private:
    bool dfs(TreeNode* root, int target) {
        // was leaf?
        if (!root->left && !root->right && root->val == target) {
            return true;
        }
        
        // was not leaf
        
        if (root->left) {
            bool del = dfs(root->left, target);
            
            if (del) {
                root->left = nullptr;
            }
        }
        if (root->right) {
            bool del = dfs(root->right, target);
            
            if (del) {
                root->right = nullptr;
            }
        }
        
        // is leaf now?
        if (!root->left && !root->right && root->val == target) {
            return true;
        }
        
        return false;
    }
};

// Runtime: 20 ms, faster than 84.08% of C++ online submissions for Delete Leaves With a Given Value.
// Memory Usage: 21.7 MB, less than 100.00% of C++ online submissions for Delete Leaves With a Given Value.
// time complexity: O(n)
// space complexity: O(1)