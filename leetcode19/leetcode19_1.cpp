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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* first = head, *second = head;
        
        if(n == 0){
            return head;
        }
        
        if(first->next == NULL && n == 1){//remove the only item
            return head->next;
        }
        
        //Advances first pointer so that the gap between first and second is n nodes apart
        for(int i = 0; i <= n; i++){
            
            if(first == NULL){
                if(i != n){// n is bigger than the size of the list
                    return head;
                }
                else{//i == n, remove head
                    return head->next;
                }
            }
            
            first = first->next;
        }
        
        //Move first to the end, maintaing the gap
        while(first != NULL){
            if(n == 1 && first->next == NULL){
                second->next->next = NULL;
                return head;
            }
            
            first = first->next;
            second = second->next;
        }
        
        second->next = second->next->next;
        return head;
    }
};
// Runtime: 4 ms, faster than 89.71% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.4 MB, less than 89.88% of C++ online submissions for Remove Nth Node From End of List.
// time complexity: O(2 * n)
// space complexity: O(1)