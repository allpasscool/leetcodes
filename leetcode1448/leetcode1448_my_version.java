/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public int goodNodes(TreeNode root) {
        return findGoodNodes(root, root.val);
    }

    private int findGoodNodes(TreeNode root, int preMax) {
        if (root == null)
            return 0;

        int good = 0;

        if (root.val >= preMax)
            good += 1;

        good += findGoodNodes(root.left, Math.max(preMax, root.val));
        good += findGoodNodes(root.right, Math.max(preMax, root.val));

        return good;
    }
}

// Runtime: 2 ms, faster than 97.82% of Java online submissions for Count Good
// Nodes in Binary Tree.
// Memory Usage: 47.8 MB, less than 51.91% of Java online submissions for Count
// Good Nodes in Binary Tree.
// time complexity: O(n)
// space complexity: O(log n)