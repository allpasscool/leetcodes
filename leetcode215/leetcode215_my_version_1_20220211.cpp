class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();

        sort(begin(nums), end(nums));

        return nums[n - k];
    }
};

// Runtime: 8 ms, faster than 82.04% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10 MB, less than 59.21% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(n log n)
// space complexity: O(1)