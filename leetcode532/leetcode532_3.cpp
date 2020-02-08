class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pre = 0;
        unordered_set<int> hashset;
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int tmp = sum;
            
            if (k != 0)
                tmp %= k;
            
            if (hashset.find(tmp) != hashset.end()) {
                return true;
            }
            
            hashset.insert(pre);
            pre = tmp;
        }
        
        return false;
    }
};


// Runtime: 28 ms, faster than 81.96% of C++ online submissions for Continuous Subarray Sum.
// Memory Usage: 11.5 MB, less than 85.00% of C++ online submissions for Continuous Subarray Sum.
// time complexity: O(n)
// space complexity: O(n)

// class Solution {
// public:
//     bool checkSubarraySum(vector<int>& nums, int k) {
//         int n = nums.size(), sum = 0, pre = 0;
//         unordered_set<int> modk;
//         for (int i = 0; i < n; ++i) {
//             sum += nums[i];
//             int mod = k == 0 ? sum : sum % k;
//             if (modk.count(mod)) return true;
//             modk.insert(pre);
//             pre = mod;
//         }
//         return false;
//     }
// };
// https://leetcode.com/problems/continuous-subarray-sum/discuss/99506/Concise-C%2B%2B-solution-use-set-instead-of-map

