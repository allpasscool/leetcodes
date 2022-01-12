class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int count = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                count++;
        }

        int left = 0, right = count - 1;
        int cur = 0;
        for (int i = 0; i <= right; i++)
        {
            if (nums[i] == 1)
                cur++;
        }
        int maxAns = cur;

        while (right < nums.size() - 1)
        {
            if (nums[left] == 1)
                cur--;
            left++;
            right++;
            if (nums[right] == 1)
                cur++;

            if (cur > maxAns)
                maxAns = cur;
        }

        // tail
        cur = 0;
        left = nums.size() - count + 1;
        right = 0;

        if (nums[right] == 1)
            cur++;
        for (int i = left; i < nums.size(); i++)
        {
            if (nums[i] == 1)
                cur++;
        }

        if (cur > maxAns)
            maxAns = cur;

        while (left < nums.size())
        {
            if (nums[left] == 1)
                cur--;
            left++;
            right++;
            if (nums[right] == 1)
                cur++;

            if (cur > maxAns)
                maxAns = cur;
        }

        return count - maxAns;
    }
};

// Runtime: 221 ms, faster than 9.34% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// Memory Usage: 80.4 MB, less than 73.41% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// time complexity: O(n)
// space complexity: O(1)