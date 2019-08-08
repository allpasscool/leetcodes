class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        
        //left most and right most won't trap any water, therefore we don't need to worry
        for (int i = 1; i + 1 < height.size(); i ++) {
            int max_left = 0;
            
            //find left most
            for (int j = i - 1; j >= 0; j--) {
                if (height[j] > max_left) {
                    max_left = height[j];
                }
            }
            
            int max_right = 0;
            
            //find right most
            for (int j = i + 1; j < height.size(); j++) {
                if (height[j] > max_right) {
                    max_right = height[j];
                }
            }
            
            int h_min = min(max_left, max_right);
            
            if (h_min > height[i]) {
                sum += h_min - height[i];
            }
        }
        
        return sum;
    }
};
// Runtime: 192 ms, faster than 5.01% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9 MB, less than 97.47% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n^2)
// space complexity: O(1)