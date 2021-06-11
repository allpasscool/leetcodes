/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    public int rangeSumBST(TreeNode root, int low, int high) {
        if (root == null)
            return 0;

        int sum = 0;

        if (root.val >= low && root.val <= high) {
            sum += root.val;
        }
        sum += rangeSumBST(root.left, low, high);
        sum += rangeSumBST(root.right, low, high);

        return sum;
    }
}

// Runtime: 1 ms, faster than 51.76% of Java online submissions for Range Sum of
// BST.
// Memory Usage: 63.7 MB, less than 8.80% of Java online submissions for Range
// Sum of BST.
// time complexity: O(n)
// space complexity: O(log n)