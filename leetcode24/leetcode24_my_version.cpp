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
    ListNode* swapPairs(ListNode* head) {
        ListNode *first, *second, *before_next, *tmp;
        
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        first = head;
        second = head->next;
        tmp = second->next;
        
        head = second;
        second->next = first;
        first->next = tmp;
        before_next = first;
        
        while(before_next->next != NULL && before_next->next->next != NULL){
            first = before_next->next;
            second = before_next->next->next;
            tmp = second->next;
            
            before_next->next = second;
            second->next = first;
            first->next = tmp;
            before_next = first;
        }
        
        return head;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// Memory Usage: 8.8 MB, less than 23.53% of C++ online submissions for Swap Nodes in Pairs.
// time complexity: O(n)
// space complexity: O(1)