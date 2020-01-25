class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farthest = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            if (farthest < i) {
                return false;
            }
                
            farthest = max(farthest, i + nums[i]);
        }
        
        return true;
    }
};


// Runtime: 12 ms, faster than 72.83% of C++ online submissions for Jump Game.
// Memory Usage: 9.9 MB, less than 77.63% of C++ online submissions for Jump Game.
// time complexity: O(n)
// space complexity: O(1)