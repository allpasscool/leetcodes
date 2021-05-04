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
        Queue<TreeNode> left = new LinkedList<>();
        Queue<TreeNode> right = new LinkedList<>();
        
        // add root left
        if (root.left != null) {
            left.add(root.left);
        }
        else {
            left.add(null);
        }
        // add root right
        if (root.right != null) {
            right.add(root.right);
        }
        else {
            right.add(null);
        }
        
        while (!left.isEmpty() && !right.isEmpty()) {
            TreeNode left_node = left.poll();
            TreeNode right_node = right.poll();
            
            // only one of node is null
            if ((left_node == null && right_node != null)
                || left_node != null && right_node == null) {
                return false;
            }
            else if (left_node == null && right_node == null) {
                continue;
            }
            else if (left_node.val != right_node.val) {
                return false;
            }
            // equal
            else {
                // first pair
                if (left_node.left != null)
                    left.add(left_node.left);
                else
                    left.add(null);
                
                if (right_node.right != null)
                    right.add(right_node.right);
                else
                    right.add(null);
                
                // second pair
                if (left_node.right != null)
                    left.add(left_node.right);
                else
                    left.add(null);
                
                if (right_node.left != null)
                    right.add(right_node.left);
                else
                    right.add(null);
            }
        }
        
        return true;
    }
}

// Runtime: 1 ms, faster than 22.97% of Java online submissions for Symmetric Tree.
// Memory Usage: 38.7 MB, less than 5.56% of Java online submissions for Symmetric Tree.
// time complexity: O(n)
// space complexity: O(n/2)