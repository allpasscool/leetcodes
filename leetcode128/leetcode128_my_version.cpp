class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        int longest_all = 1, longest_tmp = 1;
        int num = nums[0];
        
        for (int i = 1; i < n; i++) {
            if (nums[i] == num) {
                continue;
            }
            else if (nums[i] - num == 1) {
                longest_tmp++;
                num = nums[i];
            }
            else {
                longest_all = max(longest_all, longest_tmp);
                longest_tmp = 1;
                num = nums[i];
            }
        }
        
        longest_all = max(longest_all, longest_tmp);
        
        return longest_all;
    }
};
// Runtime: 8 ms, faster than 94.86% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 9.1 MB, less than 98.08% of C++ online submissions for Longest Consecutive Sequence.
// time complexity: O(nlogn)
// space complexity: O(1)