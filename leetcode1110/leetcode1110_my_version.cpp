/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // vector<TreeNode*> nodes;
        vector<TreeNode*> ans;
        
        // push to_delete value into hashset
        unordered_set<int> deleteSet;
        for (int n : to_delete)
        {
            deleteSet.insert(n);
        }
        
        // check whether root will be deleted
        if (deleteSet.find(root->val) == deleteSet.end())
            ans.push_back(root);
        
        dfs(root, deleteSet, ans);
        
        return ans;
    }
    
    void dfs(TreeNode* root, unordered_set<int> deleteSet, vector<TreeNode*>& ans)
    {
        if (deleteSet.find(root->val) != deleteSet.end())
        {
            if (root->left != NULL && deleteSet.find(root->left->val) == deleteSet.end())
                ans.push_back(root->left);
            if (root->right != NULL && deleteSet.find(root->right->val) == deleteSet.end())
                ans.push_back(root->right);
        }
        
        if (root->left)
        {
            TreeNode* left = root->left;
            if (deleteSet.find(root->left->val) != deleteSet.end())
                root->left = NULL;
            dfs(left, deleteSet, ans);
        }
        if (root->right)
        {
            TreeNode* right = root->right;
            if (deleteSet.find(root->right->val) != deleteSet.end())
                root->right = NULL;
            dfs(right, deleteSet, ans);
        }
        return;
    }
};

// Runtime: 654 ms, faster than 5.08% of C++ online submissions for Delete Nodes And Return Forest.
// Memory Usage: 108 MB, less than 6.98% of C++ online submissions for Delete Nodes And Return Forest.
// time complexity: O(n + m), n is binary tree and m is len of to_delete
// space complexity: O(log n + m)