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
        if (!root) {
            return false;
        }
        
        unordered_set<int> hashset;
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            
            int rest = k - q.front()->val;
            
            if (hashset.find(rest) != hashset.end()) {
                return true;
            }
            
            hashset.insert(q.front()->val);
            
            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }
            
            q.pop();
        }
        
        
        return false;
    }
};


// Runtime: 44 ms, faster than 56.15% of C++ online submissions for Two Sum IV - Input is a BST.
// Memory Usage: 25.9 MB, less than 40.00% of C++ online submissions for Two Sum IV - Input is a BST.
// time complexity: O(n)
// space complexity: O(n)