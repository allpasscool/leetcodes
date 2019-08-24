class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        
        for (int num: nums) {
            if (count == 0) {
                candidate = num;
            }
            
            count += (num == candidate) ? 1 : -1;
        }
        
        return candidate;
    }
};
//              2, 2, 1, 1, 1, 2, 1
// count :      1 .2 .1  0 .1 .0 .1
// candidate:   2 .2 .2 .2 .1 .1 .1
// Runtime: 20 ms, faster than 78.24% of C++ online submissions for Majority Element.
// Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Majority Element.
// time complexity: O(n)
// space complexity: O(1)