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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            // TreeNode* tmp;
            return NULL;
        }
        else if (n == 1) {
            TreeNode* root = new TreeNode(nums[0]);
            return root;
        }
        
        TreeNode* root = new TreeNode(nums[n / 2]);
        TreeNode* left = new TreeNode(nums[n / 2 / 2]);
        root->left = left;
        if (n == 2) {
            return root;
        }
        
        TreeNode* right = new TreeNode(nums[(n / 2 + n) / 2]);
        root->right = right;
        if (n == 3) {
            return root;
        }
            
        buildTree(nums, 0, n / 2 / 2, n / 2 - 1, left);
        buildTree(nums, n / 2 + 1, (n / 2 + n) / 2, n - 1, right);
        
        return root;
    }
    
    void buildTree(vector<int>& nums, int start, int mid, int end, TreeNode* root) {
        if (start >= end) {
            return;
        }
        
        if (mid == end) {
            TreeNode* left = new TreeNode(nums[start]);
            root->left = left;
        }
        else if (mid == start) {
            TreeNode* right = new TreeNode(nums[end]);
            root->right = right;
        }
        else {
            TreeNode* left = new TreeNode(nums[(start + mid) / 2]);
            root->left = left;
            TreeNode* right = new TreeNode(nums[(mid + end + 1) / 2]);
            root->right = right;
            buildTree(nums, start, (start + mid) / 2, mid - 1, left);
            buildTree(nums, mid + 1, (mid + end + 1) / 2, end, right);
        }
        
        return;
    }
};
// Runtime: 12 ms, faster than 98.32% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.1 MB, less than 91.89% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// time complexity: O(n)
// space complexity: O(log n)