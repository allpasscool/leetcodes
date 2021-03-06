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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2){
        if(list1 == NULL){
            return list2;
        }
        else if(list2 == NULL){
            return list1;
        }
        
        ListNode* head, *tail;
        if(list1->val <= list2->val){
            head = list1;
            list1 = list1->next;
        }
        else{
            head = list2;
            list2 = list2->next;
        }
        tail = head;
        
        while(list1 != NULL && list2 != NULL){
            if(list1->val <= list2->val){
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        
        if(list1 == NULL){
            tail->next = list2;
        }
        else{
            tail-> next = list1;
        }
        
        return head;
        
        
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size() == 1){
            return lists[0];
        }
        else if(lists.size() == 0){
            return NULL;
        }
        
        int interval = 1;
        
        while(interval< lists.size()){
            for(int i = 0; i + interval < lists.size(); i += interval * 2){
                lists[i] = mergeTwoLists(lists[i], lists[i+interval]);
            }
            
            interval *= 2;
        }
        
        return lists[0];
    }
};
// Runtime: 20 ms, faster than 98.89% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 10.7 MB, less than 96.36% of C++ online submissions for Merge k Sorted Lists.
// time complexity: O(n log k) merge in O(n) and do log k times
// space complexity: O(1)
