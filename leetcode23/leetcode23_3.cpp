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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        multimap<int, ListNode*> mp;//a new multimap<value, head> to store data(priority queue)
        
        for(ListNode* l: lists){
            if(l){
                mp.insert(make_pair(l->val, l));
            }
        }
        
        ListNode *head = NULL, *tail = NULL;
        
        while(!mp.empty()){
            multimap<int, ListNode*>::iterator it = mp.begin();//multimap is sorted with key value
            
            if(head == NULL){
                head = it->second;
                tail = head;
            }
            else{
                tail->next = it->second;
                tail = tail->next;
            }
            
            if(it->second->next){//if the list is not end, add next node into multimap
                mp.insert(make_pair(it->second->next->val, it->second->next));
            }
            
            mp.erase(it);//delete the smallest one which has been added to output list
        }
        
        return head;
    }
};
// Runtime: 36 ms, faster than 40.25% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 12.1 MB, less than 11.60% of C++ online submissions for Merge k Sorted Lists.
// time complexity: O(n * k log k) , sorting multimap k log k * n elements
// space complexity: O(k)