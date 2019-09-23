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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> output;
        if (!root)
            return output;
        
        queue<pair<TreeNode*, int>> bfs;
        int degree = -1;
        
        bfs.push(make_pair(root, 0));
        
        while (!bfs.empty()) {
            auto p = bfs.front();
            bfs.pop();
            int cur_degree = p.second;
            TreeNode* cur_node = p.first;
            
            if (cur_degree > degree) {
                degree = cur_degree;
                output.push_back(cur_node->val);
            }
            // cur_degree == degree
            else {
                output[degree] = cur_node->val;
            }
            
            if (cur_node->left) {
                bfs.push(make_pair(cur_node->left, cur_degree + 1));
            }
            if (cur_node->right) {
                bfs.push(make_pair(cur_node->right, cur_degree + 1));
            }
        }
        
        
        return output;
    }
};

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Binary Tree Right Side View.
// Memory Usage: 9.6 MB, less than 86.49% of C++ online submissions for Binary Tree Right Side View.
// time complexity: O(n)
// space complexity: O(n)