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
        if(l1 == NULL){
            return l2;
        }
        else if(l2 == NULL){
            return l1;
        }
        else if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};
// Runtime: 8 ms, faster than 82.90% of C++ online submissions for Merge Two Sorted Lists.
// Memory Usage: 9 MB, less than 36.01% of C++ online submissions for Merge Two Sorted Lists.
// time complexity:O(n + m)
// space complexity: O(n+m) The first call to mergeTwoLists does not return until the ends of 
// both l1 and l2 have been reached, so n + m stack frames consume O(n+m) space.