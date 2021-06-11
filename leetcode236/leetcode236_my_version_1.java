/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == p || root == q || root == null)
            return root;

        TreeNode left = lowestCommonAncestor(root.left, p, q);
        TreeNode right = lowestCommonAncestor(root.right, p, q);

        if (left != null && right != null)
            return root;
        else if (left != null)
            return left;
        else if (right != null)
            return right;
        else
            return null;
    }
}

// Runtime: 14 ms, faster than 9.77% of Java online submissions for Lowest
// Common Ancestor of a Binary Tree.
// Memory Usage: 45 MB, less than 13.26% of Java online submissions for Lowest
// Common Ancestor of a Binary Tree.
// time complexity: O(n)
// space complexity: O(log n)