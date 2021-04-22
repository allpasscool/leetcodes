/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null)
            return head;
        
        ArrayList<ListNode> copy = new ArrayList<>();
        ListNode cur = head;
        
        while (cur != null) {
            copy.add(cur);
            cur = cur.next;
        }
        
        int n = copy.size();
        for (int i = n - 1; i > 0; i--) {
            copy.get(i).next = copy.get(i - 1);
        }
        
        copy.get(0).next = null;
        
        return copy.get(n - 1);
    }
}

// Runtime: 1 ms, faster than 5.26% of Java online submissions for Reverse Linked List.
// Memory Usage: 39.8 MB, less than 5.37% of Java online submissions for Reverse Linked List.
// time complexity: O(n)
// space complexity: O(n)