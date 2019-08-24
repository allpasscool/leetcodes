class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash_map;
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        for (int i = 0; i < n; i++) {
            hash_map[nums[i]]++;
            if (hash_map[nums[i]] > n / 2) {
                return nums[i];
            }
        }
        
        return 0;
    }
};
// Runtime: 20 ms, faster than 78.24% of C++ online submissions for Majority Element.
// Memory Usage: 11.2 MB, less than 48.48% of C++ online submissions for Majority Element.
// time complexity: O(n)
// space complexity: O(n)