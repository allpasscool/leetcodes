class Solution {
public:
    int trap(vector<int>& height) {
        int output = 0;
        int left = 0, right = 0;
        
        //from left to right
        while (left < height.size() - 1 && right < height.size()) {
            //find left
            while (left < height.size() - 1) {
                if (height[left] > 0 ) {
                    break;
                } else {
                    left++;
                }
            }
            
            if (left == height.size() - 1) {
                break;
            }
            
            right = left + 1;
            //find right
            while (right < height.size()) {
                if (height[right] >= height[left]) {
                    break;
                } else {
                    right++;
                }
            }
            
            if (right == height.size()) {
                break;
            }
            
            int h = min(height[left], height[right]);
            
            //calculate this sextion[left, right]
            for (int i = left + 1; i < right; i++) {
                int amount = h - height[i];
                
                output += amount;
            }
            left = right;
        }
        
        //from right to left
        int old_left = left;
        right = height.size() - 1;
        while (right > old_left) {
            //find right
            while (right > old_left) {
                if (height[right] > 0 ) {
                    break;
                } else {
                    right--;
                }
            }
            
            if (right == old_left) {
                break;
            }
            
            left = right - 1;
            //find left
            while (left >= old_left) {
                if (height[left] >= height[right]) {
                    break;
                } else {
                    left--;
                }
            }
            
            if (left == old_left - 1) {
                break;
            }
            
            int h = min(height[left], height[right]);
            
            //calculate this sextion[left, right]
            for (int i = left + 1; i < right; i++) {
                int amount = h - height[i];
                
                if (h > 0) {
                    output += amount;
                }
            }
            right = left;
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 96.40% of C++ online submissions for Trapping Rain Water.
// Memory Usage: 9.1 MB, less than 91.14% of C++ online submissions for Trapping Rain Water.
// time complexity: O(n)
// space complexity: O(1)