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
        if(n == 0){
            return head;
        }
        
        int size_of_list = 0;
        ListNode* tmp = head;
        
        //count size of list
        while(tmp != NULL){
            tmp = tmp->next;
            size_of_list++;
        };
        
        if(n > size_of_list){//no remove
            return head;
        }
        else if(n == size_of_list){//remove head
            return head->next;
        }
        
        tmp = head;
        for(int i = 0; i < size_of_list; i++){
            if(i + n + 1 == size_of_list){
                if(n == 1){//remove tail
                    tmp->next = NULL;
                    return head;
                }
                else{
                    tmp->next = tmp->next->next;
                    return head;
                }
            }
            else{
                tmp = tmp->next;
            }
        }
        
        return NULL;//error
        
    }
};
// Runtime: 4 ms, faster than 89.71% of C++ online submissions for Remove Nth Node From End of List.
// Memory Usage: 8.5 MB, less than 73.92% of C++ online submissions for Remove Nth Node From End of List.
// time complexity: O(2 * n)
// space complexity:O(1)