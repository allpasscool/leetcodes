class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> diff; // difference between count of zeros and ones
        diff[0] = -1; // the diff is 0 before start to count
        int max_len = 0, count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1)
                ++count;
            else
                count--;
            
            // this count show before
            if (diff.find(count) != diff.end()) {
                max_len = max(max_len, i - diff[count]);
            }
            else {
                diff[count] = i;
            }
        }
        
        return max_len;
    }
};

// Runtime: 132 ms, faster than 41.40% of C++ online submissions for Contiguous Array.
// Memory Usage: 19.7 MB, less than 91.67% of C++ online submissions for Contiguous Array.
// time complexity: O(n)
// space complexity: O(n)