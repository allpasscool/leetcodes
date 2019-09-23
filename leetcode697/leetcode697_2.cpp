class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> num_map;
        int degree = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            int n = nums[i];

            num_map[n].push_back(i);
            degree = max(degree, (int) num_map[n].size());
        }
        
        int smallest_len = nums.size();
        
        for (auto& p: num_map) {
            if (p.second.size() == degree) {
                smallest_len = min(smallest_len, p.second[degree - 1] - p.second[0] + 1);
            }
        }
        
        return smallest_len;
    }
};

// Runtime: 36 ms, faster than 90.62% of C++ online submissions for Degree of an Array.
// Memory Usage: 15.3 MB, less than 27.27% of C++ online submissions for Degree of an Array.
// time complexity: O(n)
// space complexity: O(n)