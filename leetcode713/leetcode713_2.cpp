class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) {
            return 0;
        }
        
        int production = 1, ans = 0, left = 0;
        
        for (int right = 0; right < nums.size(); right++) {
            production *= nums[right];
            while (production >= k) {
                production /= nums[left];
                left++;
            }
            // subarray end at nums[right]
            ans += right - left + 1;
        }
        
        return ans;
    }
};
// Runtime: 132 ms, faster than 61.34% of C++ online submissions for Subarray Product Less Than K.
// Memory Usage: 18.3 MB, less than 60.00% of C++ online submissions for Subarray Product Less Than K.
// time complexity: O(n)
// space complexity: O(1)