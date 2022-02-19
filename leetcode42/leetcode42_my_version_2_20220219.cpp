class Solution
{
public:
    int trap(vector<int> &height)
    {
        int n = height.size();
        int leftMax = 0, rightMax = 0;
        int left = 0, right = n - 1;
        int ans = 0;

        while (left <= right)
        {
            if (height[left] < height[right])
            {
                if (height[left] < leftMax)
                {
                    // because right max >= left max
                    ans += leftMax - height[left];
                }
                else
                    leftMax = height[left];

                left++;
            }
            else
            {
                if (height[right] < rightMax)
                    ans += rightMax - height[right];
                else
                    rightMax = height[right];
                right--;
            }
        }

        return ans;
    }
};

// Runtime: 12 ms, faster than 67.06% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 17.7 MB, less than 16.44% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(1)