class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0, i = 0, j = height.size() - 1, h = 0;
        
        while(i < j){
            if(height[i] < height[j]){
                max = std::max(max, height[i] * (j - i));
                i++;
                while(height[i] <= h && i < j){
                    i++;
                }
            }
            else{
                max = std::max(max, height[j] * (j - i));
                j--;
                while(height[j] <= h && i < j){
                    j--;
                }
            }
        }
        
        return max;
    }
};
// Runtime: 16 ms, faster than 97.12% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.6 MB, less than 92.06% of C++ online submissions for Container With Most Water.
//time complexity: O(n)
//space complexity: O(1)