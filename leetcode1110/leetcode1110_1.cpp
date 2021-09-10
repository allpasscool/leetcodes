/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// Author: Huahua
class Solution {
public:
  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
    vector<TreeNode*> ans;
    unordered_set<int> s{begin(to_delete), end(to_delete)};
    function<TreeNode*(TreeNode*)> del = [&](TreeNode* n) -> TreeNode* {
      if (!n) return nullptr;
      if (n->left) n->left = del(n->left);
      if (n->right) n->right = del(n->right);
      if (!s.count(n->val)) return n;
      if (n->left) ans.push_back(n->left);
      if (n->right) ans.push_back(n->right);      
      return nullptr;
    };
    TreeNode* r = del(root);
    if (r) ans.push_back(r);
    return ans;
  }
};

// Runtime: 35 ms, faster than 22.57% of C++ online submissions for Delete Nodes And Return Forest.
// Memory Usage: 25.5 MB, less than 45.59% of C++ online submissions for Delete Nodes And Return Forest.
// time complexity: O(n)
// space complexity: O(d + h)
// https://zxi.mytechroad.com/blog/tree/leetcode-1110-delete-nodes-and-return-forest/