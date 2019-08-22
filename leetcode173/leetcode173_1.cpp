/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
private:
    vector<int> nodes_sorted;
    int index;
    
    void _inorder(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        
        _inorder(root->left);
        nodes_sorted.push_back(root->val);
        _inorder(root->right);
    }
    
public:
    BSTIterator(TreeNode* root) {
        // vector nodes_sorted containing all the nodes in the sorted order
        // pointer to the next smallest element in the BST
        index = -1;
        
        // call to flatten the input BST
        _inorder(root);
    }
    
    /** @return the next smallest number */
    int next() {
        return nodes_sorted[++index];
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return index + 1 < nodes_sorted.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// Runtime: 56 ms, faster than 65.53% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 25.3 MB, less than 10.87% of C++ online submissions for Binary Search Tree Iterator.
// time complexity: O(n)
// space complexity: O(n)