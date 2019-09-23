/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        ListNode* pre = NULL, *cur = head, *next = head->next;
        
        while (next != NULL) {
            pre = cur;
            cur = next;
            next = cur->next;
            cur->next = pre;
        }
        
        head->next = NULL;
        
        return cur;
    }
};

// Runtime: 8 ms, faster than 77.04% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for Reverse Linked List.
// time complexity: O(n)
// space complexity: O(1)