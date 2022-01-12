class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int totalOnes = 0, curOnesInWindow = 0, onesInWindow = 0, n = nums.size();
        for (int i = 0; i < n; i++)
            if (nums[i] == 1)
                totalOnes++;

        int left = 0;
        for (int right = 0; right < n * 2 && left < n; right++)
        {
            left = right - totalOnes;

            // right >= totalOnes means that the window size is as big as totalOnes
            // so we need to move left
            // why need to do "nums[left % n]"? consider [0, 0]
            // when right = 3, totalOnes = 0
            // 3 - 0 = 0 => nums[3 % n]
            if (right >= totalOnes && nums[left % n] == 1)
                curOnesInWindow--;
            if (nums[right % n] == 1)
                curOnesInWindow++;

            onesInWindow = max(curOnesInWindow, onesInWindow);
        }

        return totalOnes - onesInWindow;
    }
};

// Runtime: 96 ms, faster than 88.03% of C++ online submissions for Minimum Swaps to Group All 1's Together II.
// Memory Usage: 80.5 MB, less than 52.47% of C++ online submissions for Minimum Swaps to Group All 1's Together II.// time complexity: O(n)
// space complexity: O(1)
// https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/discuss/1676865/Python3-Java-C%2B%2B-Easy-Sliding-Window-O(n)