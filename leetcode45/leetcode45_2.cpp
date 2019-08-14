class Solution {
public:
    int jump(vector<int>& nums) {
        int pos = nums.size() - 1;
        int steps = 0;
        
        while (pos > 0) {
            
            for (int i = 0; i < nums.size() - 1; i++) {
                if (i + nums[i] >= pos) {
                    steps++;
                    pos = i;
                    break;
                }
            }
        }
        
        return steps;
    }
};
// time limit exceed
// time complexity: O(n^2)
// space complexity: O(1)