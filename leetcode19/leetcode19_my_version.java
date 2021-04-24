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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ArrayList<ListNode> copy = new ArrayList<>();
        ListNode cur = head;
        
        while (cur != null) {
            copy.add(cur);
            cur = cur.next;
        }
        
        int len = copy.size();
        
        // rmove head
        if (n == len)
            return head.next;
        // remove tail
        if (n == 1) {
            copy.get(len - 2).next = null;
            return head;
        }
            
        // remove nth node from end of list
        copy.get(len - 1 - n).next = copy.get(len - 1 - (n - 2));
        
        return head;
    }
}

// Runtime: 0 ms, faster than 100.00% of Java online submissions for Remove Nth Node From End of List.
// Memory Usage: 37.3 MB, less than 14.59% of Java online submissions for Remove Nth Node From End of List.
// time complexity: O(n)
// spacec complexity: O(n)