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
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL) {
            return root;
        }
        
        queue<TreeNode*> nodes;
        nodes.push(root);
        
        while (!nodes.empty()) {
            TreeNode* next_node = nodes.front();
            nodes.pop();
            
            if (!(next_node->left == NULL && next_node->right == NULL)) {
                swap (next_node->left, next_node->right);
                if (next_node->left != NULL) {
                    nodes.push(next_node->left);
                }
                if (next_node->right != NULL){
                    nodes.push(next_node->right);
                }
            }
        }
        
        return root;
    }
};
// Runtime: 4 ms, faster than 59.28% of C++ online submissions for Invert Binary Tree.
// Memory Usage: 9.1 MB, less than 96.36% of C++ online submissions for Invert Binary Tree.
// time complexity: O(n)
// spaec complexity: O(n)