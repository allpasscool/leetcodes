/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode(int x) { val = x; } }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null) {
            return root;
        }
        swapChildren(root);

        invertTree(root.left);
        invertTree(root.right);

        return root;
    }

    private void swapChildren(TreeNode root) {
        TreeNode tmp = root.left;
        root.left = root.right;
        root.right = tmp;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Invert
// Binary Tree.
// Memory Usage: 36.5 MB, less than 31.82% of Java online submissions for Invert
// Binary Tree.
// time complexity: O(n)
// space complexity: O(log n)