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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* tmp = head;
        vector<int> list_array;
        
        while (tmp != NULL) {
            if (tmp->val == 0) {
                tmp = tmp->next;
                continue;
            } 
            
            list_array.push_back(tmp->val);
            tmp = tmp->next;
        } 
        
        int n = list_array.size();
        
        for (int i = 0; i < n; i++) {
            int count = list_array[i];
            
            for (int j = i + 1; j < n; j++) {
                count += list_array[j];
                if (count == 0) {
                    if (j + 1 < n){
                        list_array.erase(list_array.begin() + i, list_array.begin() + j + 1);
                    }
                    else if (j + 1 == n) {
                        list_array.erase(list_array.begin() + i, list_array.end());
                    }
                    n = list_array.size();
                    i--;
                    break;
                }
            }
        }
        
        
        if (list_array.size() == 0) {
            head = NULL;
        }
        else {
            tmp = head;
            for (int i = 0; i < list_array.size(); i++) {
                tmp-> val = list_array[i];
                if (i != list_array.size() - 1){
                    tmp = tmp->next;
                }
                else if(i == list_array.size() - 1) {
                    tmp->next = NULL;
                }
            }
        }
        
        return head;
    }
};
// Runtime: 8 ms, faster than 98.86% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Remove Zero Sum Consecutive Nodes from Linked List.
// time complexity: O(n^2)
// space coomplexity: O(n)