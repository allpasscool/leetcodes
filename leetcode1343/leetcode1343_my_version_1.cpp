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
    int maxProduct(TreeNode* root) {
        dfs(root);
        long long ans = 0;
        
        for (auto v : vals) {
            ans = max(ans, v * (sum - v));
        }
        
        return (int)(ans % (long long)(1e9 + 7)) ;
    }

private:
    long long dfs(TreeNode* root) {
        int left = 0, right = 0;
        
        sum += root->val;
        
        if (root->left) {
            left = dfs(root->left);
            vals.push_back(left);
        }
        
        if (root->right) {
            right = dfs(root->right);
            vals.push_back(right);
        }
        
        return left + right + (long long) root->val;
    }
    
    vector<long long> vals;
    long long sum;
};


// Runtime: 164 ms, faster than 100.00% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// Memory Usage: 66.4 MB, less than 100.00% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// time complexity: O(n)
// space complexity: O(n)