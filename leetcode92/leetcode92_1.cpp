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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* before_m = dummy;
        
        // move before_m to m - 1;
        for (int i = 0; i < m - 1; ++i) {
            before_m = before_m->next;
        }
        
        ListNode* prev = before_m;
        ListNode* cur = before_m->next;
        ListNode* tail = before_m->next;
        
        // Reverse from m to n
        for (int i = m; i <= n; ++i) {
            ListNode* next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        
        // connect 3 parts
        before_m->next = prev;
        tail->next = cur;
        
        return dummy->next;
    }
};


// Runtime: 4 ms, faster than 67.57% of C++ online submissions for Reverse Linked List II.
// Memory Usage: 8.6 MB, less than 87.50% of C++ online submissions for Reverse Linked List II.
// time complexity: O(n)
// space complexity: O(n)
// https://zxi.mytechroad.com/blog/list/leetcode-92-reverse-linked-list-ii/

// // Author: Huahua
// class Solution {
// public:
//   ListNode* reverseBetween(ListNode* head, int m, int n) {
//     ListNode dummy(0);
//     dummy.next = head;
//     ListNode* p = &dummy;
//     // Find the m-1 th node
//     for (int i = 0; i < m - 1; ++i) 
//       p = p->next;
//     ListNode* prev = p;
//     ListNode* curr = p->next;
//     ListNode* tail = curr;    
//     // Reverse from m to n
//     for (int i = m; i <= n; ++i) {
//       ListNode* next = curr->next;
//       curr->next = prev;
//       prev = curr;
//       curr = next;
//     }    
//     //  Connect three parts
//     p->next = prev;
//     tail->next = curr;
//     return dummy.next;
//   }
// };