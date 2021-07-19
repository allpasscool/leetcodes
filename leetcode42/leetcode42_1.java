class Solution {
    public int trap(int[] height) {
        int left = 0, right = height.length - 1;
        int volume = 0;
        int leftMax = 0, rightMax = 0;
        
        while (left < right)
        {
            if (height[left] < height[right])
            {
                if (height[left] >= leftMax)
                {
                    leftMax = height[left];
                }
                else
                {
                    volume += leftMax - height[left];
                }
                left++;
            }
            else
            {
                if (height[right] >= rightMax)
                {
                    rightMax = height[right];
                }
                else
                {
                    volume += rightMax - height[right];
                }
                right--;
            }
        }
        
        return volume;
    }
}

// Runtime: 1 ms, faster than 85.61% of Java online submissions for Trapping Rain Water.
// Memory Usage: 38.5 MB, less than 71.41% of Java online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(1)