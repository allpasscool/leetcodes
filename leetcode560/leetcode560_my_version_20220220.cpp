class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        unordered_map<int, int> accumulatedSum;

        // no any element
        accumulatedSum[0]++;
        int accu = 0;
        int ans = 0;

        for (int num : nums)
        {
            accu += num;
            if (accumulatedSum.find(accu - k) != accumulatedSum.end())
                ans += accumulatedSum[accu - k];

            accumulatedSum[accu]++;
        }

        return ans;
    }
};

// Runtime: 72 ms, faster than 92.46% of C++ online submissions for Subarray Sum Equals K.
// Memory Usage: 36.1 MB, less than 86.82% of C++ online submissions for Subarray Sum Equals K.
// time complexity: O(n)
// space complexity: O(n)