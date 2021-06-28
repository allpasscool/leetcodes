class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        if (n <= 4)
        {
            return 0;
        }
        int minDiff = INT_MAX;

        for (int i = 0; i <= 3; i++)
        {
            minDiff = min(nums[n - 4 + i] - nums[i], minDiff);
        }

        return minDiff;
    }
};

// Runtime: 84 ms, faster than 79.80% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
// Memory Usage: 35.2 MB, less than 86.33% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
// time complexity: O(n log n)
// space complexity: O(1)