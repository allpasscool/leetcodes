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
        // special case. 0 node
        if (!head)
            return head;

        // If there is a cycle, the fast/slow pointers will intersect at some
        // node. Otherwise, there is no cycle, so we cannot find an entrance to
        // a cycle.
        ListNode *intersect = getIntersect(head);
        if (!intersect)
            return intersect;

        // To find the entrance to the cycle, we have two pointers traverse at
        // the same speed -- one from the front of the list, and the other from
        // the point of intersection.
        ListNode *ptr1 = head;
        ListNode *ptr2 = intersect;
        while (ptr1 != ptr2)
        {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return ptr1;
    }

private:
    ListNode *getIntersect(ListNode *head)
    {
        ListNode *tortoise = head;
        ListNode *cur = head;

        // A fast pointer will either loop around a cycle and meet the slow
        // pointer or reach the `null` at the end of a non-cyclic list.
        while (cur && cur->next)
        {
            tortoise = tortoise->next;
            cur = cur->next->next;
            if (tortoise == cur)
                return tortoise;
        }

        return NULL;
    }
};

// Runtime: 11 ms, faster than 40.57% of C++ online submissions for Linked List Cycle II.
// Memory Usage: 7.7 MB, less than 32.48% of C++ online submissions for Linked List Cycle II.
// time complexity: O(n)
// space complexity: O(1)