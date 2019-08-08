class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) {
            return 0;
        }
        
        int ans = 0, size = height.size();
        vector<int> left_max(size), right_max(size);
        
        left_max[0] = height[0];
        
        //dp left_max
        for (int i = 1; i < size; i++) {
            left_max[i] = max(height[i], left_max[i - 1]);
        }
        
        right_max[size - 1] = height[size - 1];
        
        //dp right_max
        for (int i = size - 2; i >= 0; i--) {
            right_max[i] = max(height[i], right_max[i + 1]);
        }
        
        //calculate trapped water
        for (int i = 1; i < size - 1; i++) {
            ans += min(left_max[i], right_max[i]) - height[i];
        }
        
        return ans;
    }
};
// Runtime: 4 ms, faster than 96.40% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.3 MB, less than 34.18% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(n)