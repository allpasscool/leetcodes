class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> output;
        long prev = (long) lower - 1;
        
        for (int i = 0; i <= nums.size(); i++) {
            long cur = (i == nums.size()) ? (long) upper + 1 : nums[i];
            
            if (cur - prev >= 2) {
                output.push_back(getRange(prev + 1, cur - 1));
            }
            
            prev = cur;
        }
        
        return output;
    }
    
    string getRange(long left, long right) {
        return left == right ? to_string(left) : (to_string(left) + "->" + to_string(right));
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Missing Ranges.
// Memory Usage: 8.4 MB, less than 100.00% of C++ online submissions for Missing Ranges.
// time complexity: O(n)
// space complexity: O(1)