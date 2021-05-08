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
    List<Integer> rightside = new ArrayList();
    
    public void dfs(TreeNode node, int level) {
        if (level == rightside.size()) 
            rightside.add(node.val);
        
        if (node.right != null) 
            dfs(node.right, level + 1);  
        if (node.left != null) 
            dfs(node.left, level + 1);
    }    
    
    public List<Integer> rightSideView(TreeNode root) {
        if (root == null) return rightside;
        
        dfs(root, 0);
        return rightside;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Binary Tree Right Side View.
// Memory Usage: 37.8 MB, less than 23.40% of Java online submissions for Binary Tree Right Side View.
// Time complexity: O(N) since one has to visit each node.
// Space complexity: O(H) to keep the recursion stack, where H is a tree height. 
// The worst-case situation is a skewed tree, when H = N.