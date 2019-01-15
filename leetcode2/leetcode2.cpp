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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* sum = new ListNode(0);
        struct ListNode* head = sum;
        int carry = 0;
        while(l1 || l2){
            if(l1){
                carry += l1->val;
                l1 = l1->next;
            }
            if(l2){
                carry += l2->val;
                l2 = l2->next;
            }
            sum->val = (carry % 10);
            carry /= 10;
            if(!l1 && !l2 && carry == 0){
                break;
            }
            sum->next = new ListNode(carry);
            sum = sum->next;
        }
        
        
        return head;
    }
};