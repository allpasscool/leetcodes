class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashmap; // hashmap[value] = index;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap.find(target - nums[i]) != hashmap.end()) {
                return {hashmap[target - nums[i]], i};
            }
            
            hashmap[nums[i]] = i;
        }
        
        return {};
    }
};


// Runtime: 8 ms, faster than 92.85% of C++ online submissions for Two Sum.
// Memory Usage: 10.1 MB, less than 55.31% of C++ online submissions for Two Sum.
// time complexity: O(n)
// space complexity: O(n)