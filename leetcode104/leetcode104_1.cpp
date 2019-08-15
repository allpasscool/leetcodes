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
    // The queue that contains the next nodes to visit.
    //  along with the level/depth that each node is located.
    queue<pair<TreeNode*, int>> next_items;
    int max_depth = 0;
    
    /**
    *   A tail recursion function to calculate the max depth
    *   of the binary tree
    */
    int next_maxDepth() {
        
        if (next_items.size() == 0) {
            return max_depth;
        }
        
        pair<TreeNode*, int> next_item = next_items.front();
        next_items.pop();//pop the first element, the front
        
        TreeNode* next_node = next_item.first;
        int next_level = next_item.second + 1;
        
        max_depth = max(max_depth, next_level);
        
        // Add the nodes to visit in the following recursive calls.
        if (next_node->left != NULL) {
            next_items.push(make_pair(next_node->left, next_level));
        }
        if (next_node->right != NULL) {
            next_items.push(make_pair(next_node->right, next_level));
        }
        
        // The last action could be the ONLY recursive call
        // in the tail-revursion function
        return next_maxDepth();
    }
    
    int maxDepth(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        // clear the previous queue.
        queue<pair<TreeNode*, int>> empty;
        swap(next_items, empty);
        max_depth = 0;
        
        // push the root node into the queue to kick off the next visit.
        next_items.push(make_pair(root, 0));
        
        return next_maxDepth();
    }
};
// Runtime: 8 ms, faster than 86.95% of C++ online submissions for Maximum Depth of Binary Tree.
// Memory Usage: 22.5 MB, less than 5.49% of C++ online submissions for Maximum Depth of Binary Tree.
// time complexity: O(n)
// space complexity: O(n)