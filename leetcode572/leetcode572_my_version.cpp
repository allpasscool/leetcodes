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
    bool isSubtree(TreeNode* s, TreeNode* t) {
        queue<TreeNode*> q;
        q.push(s);
        TreeNode* sub_root = nullptr;
        bool ans = false;
        
        while (!q.empty()) {
            auto cur = q.front();
            q.pop();
            
            if (cur->val == t->val) {
                sub_root = cur;
                ans = checkSubtree(sub_root, t);
                
                if (ans)
                    return ans;
            }
            
            if (cur->left)
                q.push(cur->left);
            if (cur->right)
                q.push(cur->right);
        }
        
        // doesn't find a node match t
        // if (!sub_root)
        //     return ans;
        
        
        
        return ans;
    }
private:
    bool checkSubtree(TreeNode* sub_root, TreeNode* t) {
        // empty queue
        queue<TreeNode*> q1; // tree1
        queue<TreeNode*> q2; // tree2
        
        q1.push(sub_root);
        q2.push(t);
        
        while (!q1.empty()) {
            auto cur1 = q1.front();
            q1.pop();
            auto cur2 = q2.front();
            q2.pop();
            
            if (cur1->val != cur2->val){
                return false;
            }
            
            
            if (cur1->left && !cur2->left
               || cur1->right && !cur2->right
               || !cur1->left && cur2->left
               || !cur1->right && cur2->right) {
                return false;
            }
            
            
            if (cur1->left && cur2->left) {
                q1.push(cur1->left);
                q2.push(cur2->left);
            }
            if (cur1->right && cur2->right) {
                q1.push(cur1->right);
                q2.push(cur2->right);
            }
        }
        
        return true;
    }
};

// Runtime: 32 ms, faster than 50.11% of C++ online submissions for Subtree of Another Tree.
// Memory Usage: 33.3 MB, less than 6.25% of C++ online submissions for Subtree of Another Tree.
// time complexity: O(n^2)
// space complexity: O(n)