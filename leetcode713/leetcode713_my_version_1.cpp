class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] >= k) {
                continue;
            }
            
            // nums[i]
            count++;
            int accumulated = nums[i];
            
            for (int j = i + 1; j < n; j++) {
                // avoid nums[j] * accumulated > INT_MAX
                // which is overflow
                if (k / nums[j] < accumulated) {
                    break;
                }
                
                accumulated *= nums[j];
                if (accumulated < k) {
                    count++;
                }
                else {
                    break;
                }
            }
        }
        
        return count;
    }
};
// Time Limit Exceeded
// time complexity: O(n^2)
// space complexity: O(1)