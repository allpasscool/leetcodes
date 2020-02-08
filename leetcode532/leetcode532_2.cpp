class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int, int> hashmap;
        unordered_set<int> hashset;
        hashmap[0] = -1; // [0, 0] 0
        
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            
            if (k != 0)
                sum %= k;
            
            if (hashmap.find(sum) != hashmap.end()) {
                if (i - hashmap[sum] > 1) {
                    return true;
                }
            }
            else {
                hashmap[sum] = i;
            }
        }
        
        return false;
    }
};

// Runtime: 24 ms, faster than 96.01% of C++ online submissions for Continuous Subarray Sum.
// Memory Usage: 11.6 MB, less than 40.00% of C++ online submissions for Continuous Subarray Sum.
// time complexity: O(n)
// space complexity: O(n)