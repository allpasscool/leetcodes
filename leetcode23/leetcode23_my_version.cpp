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
        ListNode* head = NULL, *output_tail = NULL;
        bool end = true;//all vector reach tail which will be pointing to NULL
        do{
            ListNode* smallest = NULL;
            int smallest_pos;
            end = true;
            
            //traverse vector
            for(int i = 0; i < lists.size(); i++){
                if(lists[i] != NULL){
                    end = false;
                    if(smallest == NULL || smallest->val > lists[i]->val){
                        smallest = lists[i];
                        smallest_pos = i;
                        if(output_tail != NULL && output_tail->val == smallest->val){
                            break;
                        }
                    }
                }

            }
            
            if(!end){
                lists[smallest_pos] = lists[smallest_pos]->next;
                
                if(head == NULL){
                    head = smallest;
                    output_tail = head;
                }
                else{
                    output_tail->next = smallest;
                    output_tail = output_tail->next;
                }
            }
        }while(!end);
        
        return head;
    }
};
// Runtime: 232 ms, faster than 20.40% of C++ online submissions for Merge k Sorted Lists.
// Memory Usage: 10.8 MB, less than 91.81% of C++ online submissions for Merge k Sorted Lists.
// time complexity: O(n * k), n is the length of all nodes, k is the size of vector
// space complexity: O(1)