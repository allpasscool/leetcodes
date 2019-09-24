class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int non_zero = 0; // where next non_zero put
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != 0) {
                nums[non_zero]  = nums[i];
                ++non_zero;
            }
        }
        
        // put 0 at end of nums
        for (int i = non_zero; i < n; ++i) {
            nums[i] = 0;
        }
        
        return;
    }
};

// Runtime: 16 ms, faster than 61.70% of C++ online submissions for Move Zeroes.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Move Zeroes.
// time complexity: O(n)
// space complexity: O(1)