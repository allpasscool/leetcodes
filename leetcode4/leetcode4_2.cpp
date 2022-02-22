class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        int m = nums1.size();
        int n = nums2.size();
        // make sure m <= n
        if (m > n)
            return findMedianSortedArrays(nums2, nums1);

        int left = 0, right = m;
        while (left <= right)
        {
            int p1 = left + (right - left) / 2;
            int p2 = (m + n + 1) / 2 - p1;

            int left1 = p1 == 0 ? INT_MIN : nums1[p1 - 1];
            int right1 = p1 == m ? INT_MAX : nums1[p1];
            int left2 = p2 == 0 ? INT_MIN : nums2[p2 - 1];
            int right2 = p2 == n ? INT_MAX : nums2[p2];

            if (left1 > right2)
            {
                right = p1 - 1;
            }
            else if (left2 > right1)
            {
                left = p1 + 1;
            }
            else
            {
                int max_left = left1 > left2 ? left1 : left2;
                int min_right = right1 > right2 ? right2 : right1;
                if ((m + n) % 2 == 1)
                    return max_left; // # of left_part = # of right_part + 1;
                else
                    return (max_left + min_right) / 2.0;
            }
        }
        return -1;
    }
};

// https://leetcode.com/problems/median-of-two-sorted-arrays/discuss/2481/Share-my-O(log(min(mn)))-solution-with-explanation
// Runtime: 54 ms, faster than 53.00% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 89.3 MB, less than 61.96% of C++ online submissions for Median of Two Sorted Arrays.
// time complexity: O(log m)
// space complexity: O(1)