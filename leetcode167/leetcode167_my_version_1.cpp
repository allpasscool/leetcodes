class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int, int> hashmap; // hashmap[value] = index
        
        for (int i = 0; i < numbers.size(); ++i) {
            if (hashmap.find(target - numbers[i]) != hashmap.end()) {
                return {hashmap[target - numbers[i]] + 1, i + 1};
            }
            
            hashmap[numbers[i]] = i;
        } 
        
        return {};
    }
};


// Runtime: 4 ms, faster than 96.65% of C++ online submissions for Two Sum II - Input array is sorted.
// Memory Usage: 9.7 MB, less than 11.76% of C++ online submissions for Two Sum II - Input array is sorted.
// time complexity: O(n)
// space complexity: O(n)