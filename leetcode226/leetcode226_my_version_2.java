/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public TreeNode invertTree(TreeNode root) {
        if (root == null)
            return root;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode cur = q.poll();

            if (cur != null) {
                swapChildren(cur);
                q.add(cur.left);
                q.add(cur.right);
            }
        }

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
// Memory Usage: 38.6 MB, less than 5.78% of Java online submissions for Invert
// Binary Tree.
// time complexity: O(n)
// space complexity: O(n)