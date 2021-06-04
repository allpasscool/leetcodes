/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        ListNode dummy = new ListNode(-1);
        dummy.next = head;
        ListNode cur = dummy;

        while (cur != null && cur.next != null) {
            if (cur.next.val == val) {
                cur.next = cur.next.next;
            } else {
                cur = cur.next;
            }
        }

        return dummy.next;
    }
}

// Runtime: 1 ms, faster than 72.89% of Java online submissions for Remove
// Linked List Elements.
// Memory Usage: 39.6 MB, less than 75.34% of Java online submissions for Remove
// Linked List Elements.
// time complexity: O(n)
// space complexity: O(1)