/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class MyTreeNode {
public:
    TreeNode* root;
    int start;
    int end;
    
    MyTreeNode(TreeNode* r, int s, int e) {
        this->root = r;
        this->start = s;
        this->end = e;
    }
};

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.size() == 0) {
            return NULL;
        }
        
        int start = 0, end = nums.size();
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode((nums[mid]));
        
        TreeNode* curr_root = root;
        
        stack<MyTreeNode*> root_stack;
        root_stack.push(new MyTreeNode(root, start, end));
        
        while (end - start > 1 || !root_stack.empty()) {
            // left child subtree
            while (end - start > 1) { // more than one in left hand side
                mid = start + (end - start) / 2;
                end = mid;
                mid = start + (end - start) / 2;
                curr_root->left = new TreeNode(nums[mid]);
                curr_root = curr_root->left;
                root_stack.push(new MyTreeNode(curr_root, start, end));
            }
            
            // right child subtree
            MyTreeNode* my_node = root_stack.top();
            root_stack.pop();
            start = my_node->start;
            end = my_node->end;
            mid = start + (end - start) / 2;
            start = mid + 1;
            curr_root = my_node->root;
            if (start < end) {
                mid = start + (end - start) / 2;
                curr_root->right = new TreeNode(nums[mid]);
                curr_root = curr_root->right;
                root_stack.push(new MyTreeNode(curr_root, start, end));
            }
        }
        
        return root;
    }
};
// Runtime: 16 ms, faster than 85.93% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 20.5 MB, less than 97.30% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// time complexity: O(n)
// space complexity: O(log n)