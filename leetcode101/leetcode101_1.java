/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isMirror(root, root);
    }

    public boolean isMirror(TreeNode t1, TreeNode t2) {
        if (t1 == null && t2 == null) return true;
        if (t1 == null || t2 == null) return false;
        return (t1.val == t2.val)
            && isMirror(t1.right, t2.left)
            && isMirror(t1.left, t2.right);
    }
}


// Runtime: 0 ms, faster than 100.00% of Java online submissions for Symmetric Tree.
// Memory Usage: 36.9 MB, less than 75.58% of Java online submissions for Symmetric Tree.
// time complexity: O(n)
// space complexity: The number of recursive calls is bound by the height of the tree. 
// In the worst case, the tree is linear and the height is in O(n). 
// Therefore, space complexity due to recursive calls on the stack is O(n) in the worst case.