class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        
        return nums[n / 2];
    }
};
// Runtime: 28 ms, faster than 27.06% of C++ online submissions for Majority Element.
// Memory Usage: 11 MB, less than 96.97% of C++ online submissions for Majority Element.
// time complexity: O(n log n)
// space complexity: O(n)