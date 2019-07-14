class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, i = 0, j = height.size() - 1;
        
        while(i < j){
            if(height[i] < height[j]){
                max = std::max(max, height[i] * (j - i));
                i++;
            }
            else{
                max = std::max(max, height[j] * (j - i));
                j--;
            }
        }
        
        return max;
    }
};
// Runtime: 20 ms, faster than 76.85% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.9 MB, less than 21.42% of C++ online submissions for Container With Most Water.
//time complexity: O(n)
//space complexity: O(1)