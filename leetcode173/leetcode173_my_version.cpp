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
public:
    BSTIterator(TreeNode* root) {
        if (root == NULL) {
            return;
        }
        s.push(root);
        
        while (root->left) {
            s.push(root->left);
            root = root->left;
        }
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode* root = s.top();
        int output = root->val;
        s.pop();
        if (root->right) {
            root = root->right;
            s.push(root);
        }
        else {
            return output;
        }
        
        while (root->left) {
            root = root->left;
            s.push(root);
        }
        
        return output;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (s.empty()) {
            return false;
        }
        return true;
    }
private:
    stack<TreeNode*> s;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// Runtime: 56 ms, faster than 65.53% of C++ online submissions for Binary Search Tree Iterator.
// Memory Usage: 24.2 MB, less than 93.48% of C++ online submissions for Binary Search Tree Iterator.
// time complexity: O(n), average O(1)
// space complexity: O(log n)