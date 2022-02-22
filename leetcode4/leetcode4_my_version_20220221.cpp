// it is easier when you pass median then stop before knowing which one is median
class Solution
{
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        // make sure nums1.size() >= nums2.size()
        if (nums1.size() < nums2.size())
            return findMedianSortedArrays(nums2, nums1);

        int n1 = nums1.size(), n2 = nums2.size();
        int p1 = 0, p2 = 0;
        double ans = 0;

        // case 1  odd
        // [1 2 3 4 5]
        //      p1
        // []
        // p2
        // case 2  even
        // [1 2 3 4 5 6]
        //        p1
        // []
        // p2
        // case 3 even
        // [1 2 3]
        //         p1
        // [4 5 6]
        //  p2
        // case 4 odd
        // [1 2 3]
        //      p1
        // [4 5]
        // p2
        // case 5 odd
        // [1 2 5]
        //      p1
        // [3 4]
        //  p2
        // case 6 odd
        // [4 5 6]
        //  p1
        // [1 2]
        //       p2
        // case 7 even
        // [3]
        //  p1
        // [2]
        //     p2
        while (p1 + p2 <= (n1 + n2) / 2)
        {
            if (p2 >= n2 || (p1 < n1 && nums1[p1] <= nums2[p2]))
            {
                // odd
                if ((n1 + n2) % 2 == 1)
                {
                    if ((p1 + p2) == (n1 + n2) / 2)
                        ans += nums1[p1];
                }
                // even
                else
                {
                    if ((p1 + p2) == (n1 + n2) / 2 - 1)
                    {
                        ans += nums1[p1];
                    }
                    else if ((p1 + p2) == (n1 + n2) / 2)
                    {
                        ans = (double)(ans + nums1[p1]) / 2;
                    }
                }
                p1++;
            }
            else
            {
                // odd
                if ((n1 + n2) % 2 == 1)
                {
                    if ((p1 + p2) == (n1 + n2) / 2)
                        ans += nums2[p2];
                }
                else
                {
                    if ((p1 + p2) == (n1 + n2) / 2 - 1)
                    {
                        ans += nums2[p2];
                    }
                    else if ((p1 + p2) == (n1 + n2) / 2)
                    {
                        ans = (double)(ans + nums2[p2]) / 2;
                    }
                }

                p2++;
            }
        }

        return ans;
    }
};

// Runtime: 39 ms, faster than 73.01% of C++ online submissions for Median of Two Sorted Arrays.
// Memory Usage: 89.4 MB, less than 61.96% of C++ online submissions for Median of Two Sorted Arrays.
// time complexity: O(n)
// space complexity: O(1)