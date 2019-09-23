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
    ListNode* reverseList(ListNode* head) {
        if (head == NULL) {
            return head;
        }
        
        vector<ListNode*> nodes;
        ListNode* tmp = head;
        
        while (tmp != NULL) {
            nodes.push_back(tmp);
            tmp = tmp->next;
        }
        
        for (int i = nodes.size() - 1; i > 0; i--) {
            nodes[i]->next = nodes[i - 1];
        }
        
        nodes[0]->next = NULL;
        
        return nodes[nodes.size() - 1];
    }
};

// Runtime: 8 ms, faster than 77.04% of C++ online submissions for Reverse Linked List.
// Memory Usage: 9.3 MB, less than 48.85% of C++ online submissions for Reverse Linked List.
// time complexity: O(n)
// space complexity: O(n)