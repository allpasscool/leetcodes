class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0;
        
        while (i < nums.size()) {
            if (nums[i] > 0 && nums[i] <= nums.size() && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else {
                i++;
            }
        }
        
        for (i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                break;
            }
        }
        
        return i + 1;
    }
};
// Runtime: 4 ms, faster than 65.43% of C++ online submissions for First Missing Positive.
// Memory Usage: 8.7 MB, less than 84.00% of C++ online submissions for First Missing Positive.
// time complexity: O(n)
// space complexity: O(1)