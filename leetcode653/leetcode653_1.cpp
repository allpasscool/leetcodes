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
    bool findTarget(TreeNode* root, int k) {
        vector<int> nums;
        
        inorder(root, nums);
        
        int left = 0, right = nums.size() - 1;
        
        while (left != right) {
            int sum = nums[left] + nums[right];
            
            if (sum == k) {
                return true;
            }
            else if (sum > k) {
                right--;
            }
            else {
                ++left;
            }
        }
        
        return false;
    }
    
private:
    void inorder(TreeNode* root, vector<int>& nums) {
        if (!root) {
            return;
        }
        
        if (root->left) {
            inorder(root->left, nums);
        }
        nums.push_back(root->val);
        if (root->right) {
            inorder(root->right, nums);
        }
    }
};


// Runtime: 28 ms, faster than 98.98% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 24.8 MB, less than 95.00% of C++ online submissions for Two Sum IV - Input is a BST.
// time complexity: O(n)
// space complexity: O(n)