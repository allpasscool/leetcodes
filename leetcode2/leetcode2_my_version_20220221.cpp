/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int sum = 0, carry = 0;
        ListNode *dummy = new ListNode();
        ListNode *cur = dummy;

        while (l1 || l2)
        {
            int tmp = 0;

            if (l1)
            {
                tmp += l1->val;
                l1 = l1->next;
            }
            if (l2)
            {
                tmp += l2->val;
                l2 = l2->next;
            }

            tmp += carry;

            carry = tmp / 10;
            tmp = tmp % 10;

            cur->next = new ListNode(tmp);
            cur = cur->next;
        }

        // carry?
        if (carry > 0)
            cur->next = new ListNode(carry);

        return dummy->next;
    }
};

// Runtime: 44 ms, faster than 60.59% of C++ online submissions for Add Two Numbers.
// Memory Usage: 71.4 MB, less than 49.58% of C++ online submissions for Add Two Numbers.
// time complexity: O(n)
// space complexity: O(1)