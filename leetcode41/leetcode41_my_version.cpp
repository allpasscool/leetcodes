class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int i = 1;
        
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] <= 0) {
                continue;
            }
            
            if (nums[j] == i) {
                i++;
            } else if (nums[j] > i) {
                break;
            }
        }
        
        return i;
    }
};
// Runtime: 4 ms, faster than 65.43% of C++ online submissions for First Missing Positive.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for First Missing Positive.
// time complexity: O(nlogn)
// space complexity: O(1)