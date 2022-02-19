class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        vector<int> left(n), right(n);

        int high = 0;

        for (int i = 0; i < n; i++)
        {
            left[i] = high;
            high = max(high, height[i]);
        }

        high = 0;

        for (int i = n - 1; i >= 0; i--)
        {
            right[i] = high;
            high = max(high, height[i]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++)
        {
            // special case, min(left bound, right bound) < current height
            ans += max(min(left[i], right[i]) - height[i], 0);
        }

        return ans;
    }
};

// Runtime: 11 ms, faster than 71.66% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 18.4 MB, less than 6.41% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(n)