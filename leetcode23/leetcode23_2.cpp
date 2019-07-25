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
    static bool heapComp(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> heap;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]){
                heap.push_back(lists[i]);
            }
        }
        
        if(heap.empty()){
            return NULL;
        }
        
        //vector -> heap data structure
        //in this case with heapComp, will be minimum heap,
        //since the smallest will be the front
        make_heap(heap.begin(), heap.end(), heapComp); 
        
        ListNode* head;
        
        head = heap.front();
        pop_heap(heap.begin(), heap.end(), heapComp);
        heap.pop_back();
        if(head->next){
            heap.push_back(head->next);
            push_heap(heap.begin(), heap.end(), heapComp);
        }
        
        ListNode* tail = head;
        
        
        while(!heap.empty()){
            tail->next = heap.front();
            pop_heap(heap.begin(), heap.end(), heapComp);
            heap.pop_back();
            tail = tail->next;
            
            if(tail->next){
                heap.push_back(tail->next);
                //after adding new element, reorder elements
                push_heap(heap.begin(), heap.end(), heapComp);
                
            }
        }
        
        return head;
    }
};
// Runtime: 24 ms, faster than 92.66% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 11.1 MB, less than 55.74% of C++ online submissions for Merge k Sorted Lists.
// time complexity: O(n log k) where k is the number of linked lists.
// The comparison cost will be reduced to O(logk) for every pop and insertion to priority queue. 
// But finding the node with the smallest value just costs O(1) time.
// There are N nodes in the final linked list.
// space complexity: O(k) prioirty queue 