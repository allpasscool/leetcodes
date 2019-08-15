class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int output = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            output = output ^ nums[i];
        }
        
        return output;
    }
};
//a XOR a XOR b = b
// Runtime: 16 ms, faster than 66.73% of C++ online submissions for Single Number.
// Memory Usage: 9.7 MB, less than 85.19% of C++ online submissions for Single Number.
// time complexity: O(N)
// space complexity: O(1)