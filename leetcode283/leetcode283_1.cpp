class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int last_non_zero_found_at = 0;
        
        for (int i = 0; i < n; ++i) 
            if (nums[i] != 0)
                swap(nums[last_non_zero_found_at++], nums[i]);
    }
};

// Runtime: 16 ms, faster than 61.70% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.4 MB, less than 91.67% of C++ online submissions for Move Zeroes.
// time complexity: O(n)
// space complexity: O(1)