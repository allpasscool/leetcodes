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
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        vector<pair<int, TreeNode*>> my_stack;
        my_stack.push_back(pair<int, TreeNode*>(1, root));
        int max_depth = 0;
        
        while (!my_stack.empty()) {
            pair<int, TreeNode*> my_pair = my_stack.back();
            int curr_depth = my_pair.first;
            TreeNode* curr_node = my_pair.second;
            
            max_depth = max(max_depth, curr_depth);
            my_stack.pop_back();
            
            if (curr_node->right != NULL) {
                my_stack.push_back(pair<int, TreeNode*>(curr_depth + 1, curr_node->right));
            }
            if (curr_node->left != NULL) {
                my_stack.push_back(pair<int, TreeNode*>(curr_depth + 1, curr_node->left));
            }
        }
        
        return max_depth;
    }
};
// Runtime: 12 ms, faster than 58.14% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 18.9 MB, less than 100.00% of C++ online submissions for Maximum Depth of Binary Tree.
// time complexity: O(N)
// space complexity: O(N)