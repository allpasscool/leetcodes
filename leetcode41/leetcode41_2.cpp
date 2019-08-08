class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 1;
        }
        
        int contain = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                contain++;
            } else if (nums[i] <= 0) {
                nums[i] = n + 1;
            }
        }
        
        if (contain == 0) {
            return 1;
        }
        
        if (n == 1) {
            return 2;
        }
        
        
        for (int i = 0; i < n; i++) {
            int a = abs(nums[i]);
            if (a > 0 && a <= n) {
                nums[a - 1] = -1 * abs(nums[a - 1]);
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};
// Runtime: 4 ms, faster than 65.43% of C++ online submissions for First Missing Positive.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for First Missing Positive.
// time complexity: O(n)
// space complexity: O(1)