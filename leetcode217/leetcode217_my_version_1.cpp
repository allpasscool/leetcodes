class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if (nums.size() <= 1) {
            return false;
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1])
                return true;
        }
        
        return false;
    }
};

// Runtime: 28 ms, faster than 96.82% of C++ online submissions for Contains Duplicate.
// Memory Usage: 11.3 MB, less than 95.60% of C++ online submissions for Contains Duplicate.
// time complexity: O(n log n)
// space complexity: O(1)