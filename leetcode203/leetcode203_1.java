/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return head;
        }
        head.next = removeElements(head.next, val);
        return (head.val == val) ? head.next : head;
    }
}

// Runtime: 1 ms, faster than 72.89% of Java online submissions for Remove
// Linked List Elements.
// Memory Usage: 46.7 MB, less than 5.50% of Java online submissions for Remove
// Linked List Elements.
// time complexity: O(n)
// space complexity: O(n)