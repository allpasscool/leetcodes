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
        return sortedArrayToBST(nums, 0, nums.size());
    }
private:
    TreeNode* sortedArrayToBST(vector<int>& nums, int start, int end) {
        if (start == end) {
            return NULL;
        }
        
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBST(nums, start, mid);
        root->right = sortedArrayToBST(nums, mid + 1, end);
        
        return root;
    }
};
// Runtime: 16 ms, faster than 85.91% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 21.1 MB, less than 94.59% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// time complexity: O(n)
// space complexity: O(logn)