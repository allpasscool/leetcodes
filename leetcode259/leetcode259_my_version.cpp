class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int count = 0;
        
        for (int i = 0; i < (int) nums.size() - 2; ++i) {
            int left = i + 1, right = nums.size() - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
     
                if (sum < target) {
                    count += right - left;
                    ++left;
                }
                else if (sum >= target) {
                    right--;
                }
            }
        }
        
        return count;
    }
};


// Runtime: 8 ms, faster than 79.95% of C++ online submissions for 3Sum Smaller.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for 3Sum Smaller.
// time complexity: O(n^2)
// space complexity: O(1)