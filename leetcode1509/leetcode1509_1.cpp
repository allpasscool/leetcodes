class Solution
{
public:
    int minDifference(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 5)
            return 0;

        partial_sort(nums.begin(), nums.begin() + 4, nums.end());
        nth_element(nums.begin() + 4, nums.end() - 4, nums.end());
        sort(nums.end() - 4, nums.end());

        return min({nums[n - 1] - nums[3],
                    nums[n - 2] - nums[2],
                    nums[n - 3] - nums[1],
                    nums[n - 4] - nums[0]});
    }
};

// Runtime: 76 ms, faster than 92.69% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
// Memory Usage: 35.2 MB, less than 86.33% of C++ online submissions for Minimum Difference Between Largest and Smallest Value in Three Moves.
// time complexity: O(n log k)
// space complexity: O(log k)
// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/discuss/730567/JavaC%2B%2BPython-Straight-Forward