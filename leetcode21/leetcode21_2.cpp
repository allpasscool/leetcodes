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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* head, *pre;
        
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        
        if(l1->val <= l2->val){
            head = l1;
            pre = head;
            l1 = l1->next;
        }
        else{
            head = l2;
            pre = head;
            l2 = l2->next;
        }
        
        while(l1 != NULL && l2 != NULL){
            if(l1->val <= l2->val){
                pre->next = l1;
                l1 = l1->next;
            }
            else{
                pre->next = l2;
                l2 = l2->next;
            }
            
            pre = pre->next;
        }
        
        if(l1 == NULL){
            pre->next = l2;
        }
        else{
            pre->next = l1;
        }
        
        return head;
    }
};
// Runtime: 4 ms, faster than 99.17% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 8.8 MB, less than 78.70% of C++ online submissions for Merge Two Sorted Lists.
// time complexity: O(n+m)
// space complexity:O(1)