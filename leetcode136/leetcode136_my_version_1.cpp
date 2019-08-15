class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> hash_set;
        
        for (int i = 0; i < nums.size(); i++) {
            if (hash_set.find(nums[i]) != hash_set.end()) {
                hash_set.erase(nums[i]);
            }
            else {
                hash_set.insert(nums[i]);
            }
        }
        
        return *hash_set.begin();
    }
};
// Runtime: 20 ms, faster than 34.62% of C++ online submissions for Single Number.
// Memory Usage: 11.5 MB, less than 25.93% of C++ online submissions for Single Number.
// time complexity: O(N)
// space complexity: O(N)