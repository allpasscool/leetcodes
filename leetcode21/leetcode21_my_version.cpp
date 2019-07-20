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
        ListNode* l1_tmp = l1, *l2_tmp = l2, *head;
        
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        
        if(l1->val <= l2->val){
            head = l1;
        }
        else{
            head = l2;
        }
        
        while(l1_tmp != NULL && l2_tmp != NULL){
            ListNode* tmp1, *tmp2;
            
            
            if(l1_tmp->val <= l2_tmp->val){//l1 <= l2
                while(l1_tmp->next != NULL && l1_tmp->next->val < l2_tmp->val){
                    l1_tmp = l1_tmp->next;
                }
                
                tmp1 = l1_tmp->next;
                tmp2 = l2_tmp->next;
    
                l1_tmp->next = l2_tmp;
                if(tmp1 != NULL){
                    if(tmp2 == NULL){
                        l2_tmp->next = tmp1;
                    }
                    else if(tmp2 != NULL && tmp2->val < tmp1->val){
                        l2_tmp->next = tmp2;
                    }
                    else{
                        l2_tmp->next = tmp1;
                    }
                }
            }
            else{//l2 < l1
                while(l2_tmp->next != NULL && l2_tmp->next->val < l1_tmp->val){
                    l2_tmp = l2_tmp->next;
                }
                tmp1 = l1_tmp->next;
                tmp2 = l2_tmp-> next;
                
                l2_tmp->next = l1_tmp;
                if(tmp2 != NULL){
                    if(tmp1 == NULL){
                        l1_tmp->next = tmp2;
                    }
                    else if(tmp1 != NULL && tmp2->val < tmp1->val){
                        l1_tmp->next = tmp2;
                    }
                    else{
                        l1_tmp->next = tmp1;
                    }
                }
            }
            
            l1_tmp = tmp1;
            l2_tmp = tmp2;
        }
        
        return head;
    }
};
// Runtime: 4 ms, faster than 99.17% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 8.7 MB, less than 99.45% of C++ online submissions for Merge Two Sorted Lists.
// time complexity: O(n + m), n and m are the length of two sorted list
// space complexity: O(1)