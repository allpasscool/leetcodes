/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        int sum = 0;

        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);

        while (!q.isEmpty()) {
            TreeNode cur = q.poll();
            if (cur != null) {
                if (cur.val >= low && cur.val <= high) {
                    sum += cur.val;
                }
                q.add(cur.left);
                q.add(cur.right);
            }
        }

        return sum;
    }
}

// Runtime: 21 ms, faster than 5.95% of Java online submissions for Range Sum of
// BST.
// Memory Usage: 71.6 MB, less than 5.84% of Java online submissions for Range
// Sum of BST.
// time complexity: O(n)
// space complexity: O(n)