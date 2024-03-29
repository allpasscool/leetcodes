// Author: Huahua
// Running time: 84 ms
class Solution
{
public:
    vector<double> medianSlidingWindow(vector<int> &nums, int k)
    {
        vector<double> ans;
        if (k == 0)
            return ans;
        vector<int> window(nums.begin(), nums.begin() + k - 1);
        std::sort(window.begin(), window.end());
        for (int i = k - 1; i < nums.size(); ++i)
        {
            window.push_back(nums[i]);
            auto it = prev(window.end(), 1);
            auto const insertion_point =
                std::upper_bound(window.begin(), it, *it);
            std::rotate(insertion_point, it, it + 1);
            ans.push_back((static_cast<double>(window[k / 2]) + window[(k - 1) / 2]) / 2);
            window.erase(std::lower_bound(window.begin(), window.end(), nums[i - k + 1]));
        }
        return ans;
    }
};

// Runtime: 108 ms, faster than 29.86% of C++ online submissions for Sliding Window Median.
// Memory Usage: 13.2 MB, less than 91.21% of C++ online submissions for Sliding Window Median.
// time complexity: O(n * log k)
// space complexity: O(k)
// https://zxi.mytechroad.com/blog/difficulty/hard/leetcode-480-sliding-window-median/