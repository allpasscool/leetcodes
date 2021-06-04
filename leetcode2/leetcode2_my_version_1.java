/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummyL1 = new ListNode(-1);
        ListNode prevL1 = dummyL1;
        dummyL1.next = l1;
        ListNode dummyL2 = new ListNode(-2);
        ListNode prevL2 = dummyL2;
        dummyL2.next = l2;

        while (l1 != null && l2 != null) {
            l1.val = l1.val + l2.val + carry;
            carry = l1.val / 10;
            l1.val = l1.val % 10;

            l1 = l1.next;
            l2 = l2.next;
            prevL1 = prevL1.next;
            prevL2 = prevL2.next;
        }

        // L1 is Longer than L2
        if (l1 != null && l2 == null) {
            while (l1 != null) {
                l1.val += carry;
                carry = l1.val / 10;
                l1.val %= 10;

                prevL1.next = l1;

                prevL1 = prevL1.next;
                l1 = l1.next;
            }
        }
        // L1 is shorter than L2
        else if (l1 == null && l2 != null) {
            while (l2 != null) {
                l2.val += carry;
                carry = l2.val / 10;
                l2.val %= 10;

                prevL1.next = l2;

                prevL1 = prevL1.next;
                l2 = l2.next;
            }
        }

        if (carry == 1) {
            prevL1.next = new ListNode(1);
        }

        return dummyL1.next;
    }
}

// Runtime: 2 ms, faster than 76.25% of Java online submissions for Add Two
// Numbers.
// Memory Usage: 44.9 MB, less than 5.42% of Java online submissions for Add Two
// Numbers.
// time complexity: O(n + m)
// space complexity: O(1)