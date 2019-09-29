class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long left = 0, right = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            right += nums[i];
            if (left < nums[i])
                left = nums[i];
        }
        // right become sum of all nums
        // left become the max number in nums
        
        long long ans = right;
        while (left <= right) {
            long long mid = (left + right) / 2;
            long long sum = 0;
            int count = 1;
            for (int i = 0; i < n; ++i) {
                if (sum + nums[i] > mid) {
                    ++count;
                    sum = nums[i];
                }
                else {
                    sum += nums[i];
                }
            }
            
            if (count <= m) {
                ans = min(ans, mid);
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return ans;
    }
};

// Runtime: 4 ms, faster than 76.54% of C++ online submissions for Split Array Largest Sum.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Split Array Largest Sum.
// time complexity: O(n * log(sumOfArray))
// space compleixty: O(n)