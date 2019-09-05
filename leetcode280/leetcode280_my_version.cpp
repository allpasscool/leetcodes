class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        
        for (int i = 0; i < n - 1; i++) {
            if (i % 2 == 1) {
                swap(nums[i], nums[i + 1]);
            }
        }
        
        return;
    }
};
// Runtime: 36 ms, faster than 58.32% of C++ online submissions for Wiggle Sort.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Wiggle Sort.
// time complexity: O(nlog)
// space complexity: O(1)