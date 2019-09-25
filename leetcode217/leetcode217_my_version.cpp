class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, bool> hashmap;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (hashmap[nums[i]])
                return true;
            
            hashmap[nums[i]] = true;
        }
        
        return false;
    }
};

// Runtime: 44 ms, faster than 41.98% of C++ online submissions for Contains Duplicate.
// Memory Usage: 16.4 MB, less than 73.63% of C++ online submissions for Contains Duplicate.
// time complexity: O(n)
// space complexity: O(n)