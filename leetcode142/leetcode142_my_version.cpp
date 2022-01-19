/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        unordered_set<ListNode *> checked;
        ListNode *cur = head;

        while (cur)
        {
            if (checked.find(cur) != checked.end())
                break;
            checked.insert(cur);
            cur = cur->next;
        }

        return cur;
    }
};

// time complexity: O(n)
// space cdomplexity: O(n)
// Runtime: 30 ms, faster than 5.05% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 9.6 MB, less than 10.02% of C++ online submissions for Linked List Cycle II.