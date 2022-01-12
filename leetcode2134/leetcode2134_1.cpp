class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int totalOnes = 0, curOnesInWindow = 0, onesInWindow = 0, n = nums.size();
        totalOnes = count(begin(nums), end(nums), 1);
        vector<int> nums2(n * 2);

        for (int i = 0; i < n; i++)
        {
            nums2[i] = nums2[i + n] = nums[i];
        }

        int left = 0;
        for (int right = 0; right < n * 2 && left < n; right++)
        {
            left = right - totalOnes;

            // right >= totalOnes means that the window size is as big as totalOnes
            // so we need to move left
            if (right >= totalOnes && nums2[left] == 1)
                curOnesInWindow--;
            if (nums2[right] == 1)
                curOnesInWindow++;

            onesInWindow = max(curOnesInWindow, onesInWindow);
        }

        return totalOnes - onesInWindow;
    }
};

// Runtime: 222 ms, faster than 9.04% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// Memory Usage: 87.4 MB, less than 32.34% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/discuss/1676865/Python3-Java-C%2B%2B-Easy-Sliding-Window-O(n)