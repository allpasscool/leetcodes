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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || k <= 1){
            return head;
        }
        
        int counter = 0;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* current = dummy, *current_next, *pre = dummy;
        
        while(current->next){
            current = current->next;
            counter++;
        }
        
        for(; counter >= k; counter -= k){
            current = pre->next;
            current_next = current->next;
            
            for(int i = 1; i < k; i++){
                current->next = current_next->next;
                current_next->next = pre->next;
                pre->next = current_next;
                current_next = current->next;
            }
            
            pre = current;
            
        }
        
        return dummy->next;
    }
};
// Runtime: 20 ms, faster than 76.86% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 9.6 MB, less than 95.61% of C++ online submissions for Reverse Nodes in k-Group.
// time complexity: O(2 * n)
// space complexity: O(1)