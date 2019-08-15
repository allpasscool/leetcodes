class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> nums_map;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums_map.find(nums[i]) == nums_map.end()) {
                nums_map[nums[i]] = 1;
            } 
            else {
                nums_map[nums[i]]++;
            }
        }
        
        for (auto itr = nums_map.begin(); itr != nums_map.end(); itr++) {
            if (itr->second == 1) {
                return itr->first;
            }
        }
        
        return -1;
    }
};
// Runtime: 20 ms, faster than 34.62% of C++ online submissions for Single Number.
// Memory Usage: 11.6 MB, less than 22.22% of C++ online submissions for Single Number.
// time complexity: O(N)
// space complexity: O(N)