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
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
        prefix_sum = {{0, 1}}; // prefix sum with 0 has 1, that means this current node itself can be an answer
        pathSum(root, 0, sum);
        return ans;
    }
private:
    int ans;
    unordered_map<int, int> prefix_sum;
    
    void pathSum(TreeNode* root, int cur, int sum) {
        if (!root)
            return;
        
        cur += root->val;
        ans += prefix_sum[cur - sum]; // for example, cur = 7, sum = 4 , if there is a 3, which is nums[0] + nums[1] + ... + nums[j] = 3, and  nums[j + 1] +  ... + nums[i] = 4
        ++prefix_sum[cur];
        pathSum(root->left, cur, sum);
        pathSum(root->right, cur, sum);
        prefix_sum[cur]--;
    }
};

// Runtime: 16 ms, faster than 89.74% of C++ online submissions for Path Sum III.
// Memory Usage: 18.9 MB, less than 16.13% of C++ online submissions for Path Sum III.
// time complexity: O(n)
// space complexity: O(h)
// https://zxi.mytechroad.com/blog/tree/leetcode-437-path-sum-iii/

// Author: Huahua
// Running time: 13 ms (beats 97.74%)
// public:
//   int pathSum(TreeNode* root, int sum) {
//     ans_ = 0;
//     sums_ = {{0, 1}};
//     pathSum(root, 0, sum);
//     return ans_;
//   }
// private:
//   int ans_;
//   unordered_map<int, int> sums_;
  
//   void pathSum(TreeNode* root, int cur, int sum) {
//     if (!root) return;
//     cur += root->val;
//     ans_ += sums_[cur - sum];
//     ++sums_[cur];
//     pathSum(root->left, cur, sum);
//     pathSum(root->right, cur, sum);
//     --sums_[cur];
//   }
// };