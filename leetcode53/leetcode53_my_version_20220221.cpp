class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int left = 0, right = 0, n = nums.size();
        int maxSum = INT_MIN;
        int cur = 0;

        while (right < n)
        {
            cur += nums[right];
            maxSum = max(maxSum, cur);

            if (cur < 0 || cur < nums[right])
                reduceLeft(left, right, cur, nums);

            right++;
        }

        return maxSum;
    }

    void reduceLeft(int &left, int right, int &cur, vector<int> &nums)
    {
        while (left <= right && (cur <= 0 || nums[left] <= 0 || cur < nums[right]))
        {
            cur -= nums[left];
            left++;
        }
    }
};

// Runtime: 157 ms, faster than 47.14% of C++ online submissions for Maximum Subarray.
// Memory Usage: 67.8 MB, less than 11.69% of C++ online submissions for Maximum Subarray.
// time complexity: O(n)
// space complexity: O(1)