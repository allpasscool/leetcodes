/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode() {} ListNode(int val) { this.val = val; } ListNode(int val,
 * ListNode next) { this.val = val; this.next = next; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int carry = 0;
        ListNode dummy = new ListNode(0);
        ListNode cur = dummy;

        while (l1 != null || l2 != null) {
            int sum = 0;

            if (l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            sum += carry;

            carry = sum / 10;
            cur.next = new ListNode(sum % 10);

            cur = cur.next;
        }

        if (carry > 0) {
            cur.next = new ListNode(carry);
        }

        return dummy.next;
    }
}

// Runtime: 3 ms, faster than 15.16% of Java online submissions for Add Two
// Numbers.
// Memory Usage: 44.8 MB, less than 5.42% of Java online submissions for Add Two
// Numbers.
// time complexity: O(n + m)
// space complexity: O(1)