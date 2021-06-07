/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public boolean isSubtree(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        } else if (s == null || t == null) {
            return false;
        }

        boolean cur = false;
        if (s.val == t.val) {
            cur = sameTree(s.left, t.left) && sameTree(s.right, t.right);
        }

        return cur || isSubtree(s.left, t) || isSubtree(s.right, t);
    }

    private boolean sameTree(TreeNode s, TreeNode t) {
        if (s == null && t == null) {
            return true;
        } else if (s == null || t == null) {
            return false;
        } else if (s.val == t.val) {
            return sameTree(s.left, t.left) && sameTree(s.right, t.right);
        } else {
            return false;
        }
    }
}

// Runtime: 3 ms, faster than 96.34% of Java online submissions for Subtree of
// Another Tree.
// Memory Usage: 39.1 MB, less than 60.72% of Java online submissions for
// Subtree of Another Tree.
// time complexity: O(n^2)
// space complexity: O(log n)