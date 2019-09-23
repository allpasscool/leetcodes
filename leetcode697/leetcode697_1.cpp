class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> frequency;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int degree = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];
            
            if (left[n] == NULL && n != nums[0]) {
                left[n] = i;
            }
            right[n] = i;
            
            ++frequency[n];
            degree = max(degree, frequency[n]);
        }
        
        int smallest_len = nums.size();
        
        for (auto& p: frequency) {
            if (p.second == degree) {
                smallest_len = min(smallest_len, right[p.first] - left[p.first] + 1);
            }
        }
        
        return smallest_len;
    }
};

// Runtime: 48 ms, faster than 48.72% of C++ online submissions for Degree of an Array.
// Memory Usage: 13.9 MB, less than 72.73% of C++ online submissions for Degree of an Array.
// time complexity: O(n)
// space complexity: O(n)