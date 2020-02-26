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
        return valid(root, (long long)INT_MAX + 1, (long long)INT_MIN - 1);
    }
    
private:
    bool valid(TreeNode* root, long long max_num, long long min_num) {
        if (!root)
            return true;
        
        if (root->val <= min_num
           || root->val >= max_num) {
            return false;
        }
        
        
        if (root->left) {
            if (!valid(root->left, root->val, min_num)) {
                return false;
            }
        }
        
        if (root->right) {
            if (!valid(root->right, max_num, root->val)) {
                return false;
            }
        }
        
        return true;
    }
};

// Runtime: 16 ms, faster than 64.96% of C++ online submissions for Validate Binary Search Tree.
// Memory Usage: 20.5 MB, less than 97.92% of C++ online submissions for Validate Binary Search Tree.
// time complexity: O(n)
// space complexity: O(log n)