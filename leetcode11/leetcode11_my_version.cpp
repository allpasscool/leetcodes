class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        
        for(int i = 0;i < height.size() - 1; i++){
            for(int j = i+1; j < height.size(); j++){
                int volume = std::min(height[i], height[j]) * (j - i);
                if(volume > max){
                    max = volume;
                }
            }
        }
        
        return max;
    }
};
// Runtime: 1304 ms, faster than 5.75% of C++ online submissions for Container With Most Water.
// Memory Usage: 9.8 MB, less than 40.10% of C++ online submissions for Container With Most Water.
//time complexity: O(n^2)
//space complexity: O(1)