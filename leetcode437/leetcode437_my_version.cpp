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
        queue<TreeNode*> bfs;
        
        if (!root)
            return 0;
        
        bfs.push(root);
        
        int ans = 0;
        
        while (!bfs.empty()) {
            auto cur = bfs.front();
            bfs.pop();
            
            if (!cur)
                continue;
            
            if (cur->left)
                bfs.push(cur->left);
            if (cur->right)
                bfs.push(cur->right);
            
            // from current node
            ans += dfs(cur, sum);
        }
        
        return ans;
    }
    
    int dfs(TreeNode* root, int sum) {
        if (!root) 
            return 0;
        
        int ans = 0;
        int rest_sum = sum - root->val;
        
        if (rest_sum == 0)
            ++ans;
        
        ans += dfs(root->left, rest_sum);
        ans += dfs(root->right, rest_sum);
        
        return ans;
    }
};


// Runtime: 20 ms, faster than 76.13% of C++ online submissions for Path Sum III.
// Memory Usage: 14.5 MB, less than 100.00% of C++ online submissions for Path Sum III.
// time complexity: O(n^2)
// space complexity: O(1)