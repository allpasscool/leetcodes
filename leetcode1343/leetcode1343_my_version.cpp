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
            if (v * (sum - v) >= ans) {
                ans = v * (sum - v);
            }
            else {
                break;
            }
        }
        
        return (int)(ans % (long long)(1e9 + 7)) ;
    }

private:
    long long dfs(TreeNode* root) {
        int left = 0, right = 0;
        
        sum += root->val;
        
        if (root->left) {
            left = dfs(root->left);
            vals.insert(left);
        }
        
        if (root->right) {
            right = dfs(root->right);
            vals.insert(right);
        }
        
        return left + right + (long long) root->val;
    }
    
    set<long long> vals;
    long long sum;
};


// Runtime: 276 ms, faster than 25.00% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// Memory Usage: 97.2 MB, less than 100.00% of C++ online submissions for Maximum Product of Splitted Binary Tree.
// time complexity: O(n log n)
// space complexity: O(n)