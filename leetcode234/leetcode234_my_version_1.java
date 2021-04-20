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
    public boolean isPalindrome(ListNode head) {
        List<Integer> copy = new ArrayList<>();
        
        while (head != null) {
            copy.add(head.val);
            head = head.next;
        }
        
        int n = copy.size();
        
        for (int i = 0; i < n / 2; i++) {
            if (copy.get(i) != copy.get(n - 1 - i))
                return false;
        }
        
        return true;
    }
}

// Runtime: 7 ms, faster than 42.07% of Java online submissions for Palindrome Linked List.
// Memory Usage: 51.4 MB, less than 34.21% of Java online submissions for Palindrome Linked List.
// time complexity: O(n)
// space complexity: O(n)