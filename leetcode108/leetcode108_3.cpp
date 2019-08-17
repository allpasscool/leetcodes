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
        TreeNode* root = new TreeNode(0);
        
        queue<MyTreeNode*> root_queue;
        root_queue.push(new MyTreeNode(root, 0, nums.size()));
        
        while (!root_queue.empty()) {
            MyTreeNode* my_root = root_queue.front();
            root_queue.pop();
            int start = my_root->start;
            int end = my_root->end;
            int mid = start + (end - start) / 2;
            
            TreeNode* cur_root = my_root->root;
            cur_root->val = nums[mid];
            
            if (start < mid) {
                cur_root->left = new TreeNode(0);
                root_queue.push(new MyTreeNode(cur_root->left, start, mid));
            }
            
            if (mid + 1 < end) {
                cur_root->right = new TreeNode(0);
                root_queue.push(new MyTreeNode(cur_root->right, mid + 1, end));
            }
            
        }
        
        return root;
    }
};
// Runtime: 12 ms, faster than 98.30% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// Memory Usage: 20.4 MB, less than 97.30% of C++ online submissions for Convert Sorted Array to Binary Search Tree.
// time complexity: O(n)
// space complexity: O(n)