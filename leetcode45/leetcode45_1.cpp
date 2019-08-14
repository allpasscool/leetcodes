class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int end = 0;
        int max_pos = 0;
        int steps = 0;
        
        for (int i = 0; i < n - 1; i++) {
            
            if (i + nums[i] > max_pos) {
                max_pos = i + nums[i];
            }
            
            if (i == end) {
                steps++;
                end = max_pos;
            }
        }
        
        return steps;
    }
};
// Runtime: 12 ms, faster than 70.58% of C++ online submissions for Jump Game II.
// Memory Usage: 10.2 MB, less than 70.00% of C++ online submissions for Jump Game II.
// time complexity: O(n)
// space complexity: O(1)