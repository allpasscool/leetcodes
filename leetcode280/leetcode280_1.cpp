class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n - 1; i++) {
            if ((i % 2 == 0) == (nums[i] > nums[i + 1])) {
                swap(nums[i], nums[i + 1]);
            }
        }
        
        return;
    }
};
// Runtime: 32 ms, faster than 92.54% of C++ online submissions for Wiggle Sort.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Wiggle Sort.
// time complexity: O(n)
// space complexity: O(n)