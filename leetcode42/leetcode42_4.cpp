class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ans = 0;
        int left_max = 0, right_max = 0;
        
        while (left < right) {
            if (height[left] < height[right]) {
                height[left] >= left_max ? (left_max = height[left]) : ans += (left_max - height[left]);
                left++;
            } else {
                height[right] >= right_max ? (right_max = height[right]) : ans += (right_max - height[right]);
                right--;
            }
        }
        
        return ans;
    }
};
// Runtime: 8 ms, faster than 61.31% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.1 MB, less than 84.81% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(1)