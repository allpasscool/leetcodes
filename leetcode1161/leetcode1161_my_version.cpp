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
    int maxLevelSum(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        queue<pair<int, TreeNode*>> nodes_queue;
        int cur_level = 1;
        int all_max = 0;
        int tmp_max = 0;
        int max_level = 0;
        nodes_queue.push(make_pair(1, root));
        int node_level = 0;
        TreeNode* cur_node = NULL;
        
        while (!nodes_queue.empty()) {
            pair<int, TreeNode*> cur_pair = nodes_queue.front();
            nodes_queue.pop();
            node_level = cur_pair.first;
            cur_node = cur_pair.second;
            
            if (node_level == cur_level) {
                tmp_max += cur_node->val;
            }
            else {
                if (tmp_max > all_max) {
                    all_max = tmp_max;
                    max_level = node_level - 1;
                }
                tmp_max = cur_node->val;
                cur_level = node_level;
            }
            
            
            
            if (cur_node->left != NULL) {
                nodes_queue.push(make_pair(node_level + 1, cur_node->left));
            }
            if (cur_node->right != NULL) {
                nodes_queue.push(make_pair(node_level + 1, cur_node->right));
            }
        }
        
        if (tmp_max > all_max) {
            max_level = node_level;
        }
        
        return max_level;
    }
};
// Runtime: 228 ms, faster than 66.93% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// Memory Usage: 75.5 MB, less than 100.00% of C++ online submissions for Maximum Level Sum of a Binary Tree.
// time complexity: O(n)
// space complexity: O(n)