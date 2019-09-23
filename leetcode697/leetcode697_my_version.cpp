class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> frequency;
        int degree = 0;
        
        for(auto& n: nums) {
            ++frequency[n];
            degree = max(degree, frequency[n]);
        }
        
        unordered_map<int, int> start;
        unordered_map<int, int> counter;
        int smallest_len = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            // find number with the degree
            if (frequency[nums[i]] == degree) {
                if (start[nums[i]] == 0 && nums[i] != nums[0]) {
                    start[nums[i]] = i;
                }
                
                ++counter[nums[i]];
                
                if (counter[nums[i]] == degree) {
                    smallest_len = min(smallest_len, i - start[nums[i]] + 1);
                }
            }
        }
        
        return smallest_len;
    }
};

// Runtime: 52 ms, faster than 35.78% of C++ online submissions for Degree of an Array.
// Memory Usage: 13.8 MB, less than 72.73% of C++ online submissions for Degree of an Array.
// time complexity: O(n)
// space complexity: O(n)