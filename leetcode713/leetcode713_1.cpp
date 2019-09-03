class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        
        double logk = log(k);
        vector<double> prefix(nums.size() + 1, 0);
        
        for (int i = 0; i < nums.size(); i++) {
            prefix[i + 1] = prefix[i] + log(nums[i]);
        }
        
        int ans = 0;
        
        for (int i = 0; i < prefix.size(); i++) {
            int lo = i + 1, hi = prefix.size();
            
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                if (prefix[mid]  < prefix[i] + logk) {
                    lo = mid + 1;
                }
                else {
                    hi = mid;
                }
            }
            
            ans += lo - 1 - i;
        }
        
        return ans;
    }
};
// Runtime: 172 ms, faster than 5.88% of C++ online submissions for Subarray Product Less Than K.
// Memory Usage: 26.6 MB, less than 10.00% of C++ online submissions for Subarray Product Less Than K.
// time complexity: O(n log n)
// space complexity: O(n)