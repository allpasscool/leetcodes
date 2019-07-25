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
    // this is an strucure which implements the 
    // operator overlading 
    //in this case, vector will be descending 
    //pop from top is the right most one, which is the smallest
    struct compare{
        bool operator()(const ListNode* left, const ListNode* right){
            return left->val > right->val;
        }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        //push the head of each vector to priority queue
        for(ListNode* l: lists){
            if(l){
                pq.push(l);
            }
        }
        
        if(pq.empty()){
            return NULL;
        }
        
        ListNode* head = pq.top();
        pq.pop();
        
        if(head->next){
            pq.push(head->next);
        }
        
        ListNode* tail = head;
        
        while(!pq.empty()){
            tail->next = pq.top();
            pq.pop();
            
            tail = tail->next;
            if(tail->next){
                pq.push(tail->next);
            }
        }
        
        return head;
    }
};
// Runtime: 28 ms, faster than 72.55% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11 MB, less than 71.09% of C++ online submissions for Merge k Sorted Lists.
// time complexity: O(n log k) where k is the number of linked lists.
// The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. 
// But finding the node with the smallest value just costs O(1) time.
// There are N nodes in the final linked list.
// space complexity: O(k) prioirty queue 