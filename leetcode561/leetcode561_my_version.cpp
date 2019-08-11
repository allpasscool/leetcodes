class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int output = 0;
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size(); i += 2) {
            output += nums[i];
        }
        
        return output;
    }
};
// Runtime: 72 ms, faster than 87.77% of C++ online submissions for Array Partition I.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Array Partition I.
// time complexity: O(nlog n)
// space complexity: O(1)