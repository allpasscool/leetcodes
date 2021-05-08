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
    public List<Integer> rightSideView(TreeNode root) {
        List<Integer> ans = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        
        if (root == null)
            return ans;      
        
        while (!q.isEmpty()) {
            // number of nodes in this level
            int size = q.size();
            
            ans.add(q.peek().val);
            
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                
                if (cur.right != null)
                    q.add(cur.right);
                if (cur.left != null)
                    q.add(cur.left);
            }
        }
        
        return ans;
    }
}

// Runtime: 1 ms, faster than 72.76% of Java online submissions for Binary Tree Right Side View.
// Memory Usage: 37.7 MB, less than 50.37% of Java online submissions for Binary Tree Right Side View.
// time complexity: O(n)
// space complexity: O(n)