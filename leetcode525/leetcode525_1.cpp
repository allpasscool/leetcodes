class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> diff(2 * n + 1, -2); // difference between count of zeros and ones
        diff[n] = -1; // the diff is 0 before start to count
        int max_len = 0, count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1)
                ++count;
            else
                count--;
            
            // this count show before
            // for example we meet count == 1 twice, that means betwenn these two indexes have equal 0s and 1s
            if (diff[count + n] >= -1) {
                max_len = max(max_len, i - diff[count + n]);
            }
            else {
                diff[count + n] = i;
            }
        }
        
        return max_len;
    }
};

// Runtime: 92 ms, faster than 95.32% of C++ online submissions for Contiguous Array.
// Memory Usage: 22 MB, less than 25.00% of C++ online submissions for Contiguous Array.
// time complexity: O(n)
// space complexity: O(n)