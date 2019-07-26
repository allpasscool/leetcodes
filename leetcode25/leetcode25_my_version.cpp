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
        if(k == 0 || k == 1){
            return head;
        }
        ListNode* this_round[k], *before_next, *tmp;
        
        //first round
        tmp = head;
        for(int i = 0; i < k; i++){
            if(tmp != NULL){
                this_round[i] = tmp;
                tmp = tmp->next;
            }
            else{
                return head;
            }
        }
        head = this_round[k-1];
        this_round[0]->next = head->next;
        tmp = head;
        for(int i = k - 1; i > 0; i--){
            this_round[i]->next = this_round[i-1];
        }
        before_next = this_round[0];
        
        while(true){
            tmp = before_next->next;
            for(int i = 0; i < k; i++){
                if(tmp != NULL){
                    this_round[i] = tmp;
                    tmp = tmp->next;
                }
                else{
                    return head;
                }
            }
            
            before_next->next = this_round[k-1];
            this_round[0]->next = this_round[k-1]->next;
            tmp = this_round[k-1];
            for(int i = k - 1; i > 0; i--){
                this_round[i]->next = this_round[i-1];
            }
            before_next = this_round[0];

        }
        
        return head;
    }
};
// Runtime: 20 ms, faster than 76.86% of C++ online submissions for Reverse Nodes in k-Group.
// Memory Usage: 9.7 MB, less than 81.42% of C++ online submissions for Reverse Nodes in k-Group.
// time complexity: O(2 * n)
// space complexity: O(k)