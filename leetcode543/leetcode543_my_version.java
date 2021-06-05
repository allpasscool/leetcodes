/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    int maxLen = 0;

    public int diameterOfBinaryTree(TreeNode root) {
        subtreeHeight(root);

        return maxLen;
    }

    private int subtreeHeight(TreeNode root) {
        if (root == null)
            return 0;

        int leftLen = subtreeHeight(root.left);
        int rightLen = subtreeHeight(root.right);
        maxLen = Math.max(maxLen, leftLen + rightLen);

        return Math.max(leftLen, rightLen) + 1;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Diameter of
// Binary Tree.
// Memory Usage: 39 MB, less than 32.03% of Java online submissions for Diameter
// of Binary Tree.
// time complexity: O(n)
// space complexity: O(n)