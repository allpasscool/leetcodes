class Solution {
public:
    int singleNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 2; i += 2) {
            if (nums[i] != nums[i + 1]) {
                return nums[i];
            }
        }
        
        return nums[nums.size() - 1];
    }
};
// Runtime: 24 ms, faster than 22.35% of C++ online submissions for Single Number.
// Memory Usage: 9.8 MB, less than 72.84% of C++ online submissions for Single Number.
// time complexity: O(nlogn)
// space complexity: O(1)