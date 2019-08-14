class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        int tmp_lower = lower, tmp_upper = upper;
        vector<string> output;
        
        if (nums.size() == 0) {
            if (lower == upper) {
                output.push_back(to_string(lower));
                return output;
            }
            else {
                output.push_back(to_string(lower) + "->" + to_string(upper));
                return output;
            }
        }
        
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == tmp_lower) {
                if (nums[i] == INT_MAX) {
                    break;
                }
                tmp_lower++;
            } 
            else if (nums[i] > tmp_lower) {
                tmp_upper = nums[i] - 1;
                
                if (tmp_lower == tmp_upper) {
                    output.push_back(to_string(tmp_lower));
                } 
                else {
                    output.push_back(to_string(tmp_lower) + "->" + to_string(tmp_upper));
                }
                
                if (nums[i] == INT_MAX) {
                    break;
                }
                tmp_lower = nums[i] + 1;
            }
        }
        
        if (nums[nums.size() - 1] < upper) {
            if (nums[nums.size() - 1] == upper - 1) {
                output.push_back(to_string(upper));
            }
            else {
                output.push_back(to_string(nums[nums.size() - 1] + 1) 
                                 + "->" + to_string(upper));
            }
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 54.26% of C++ online submissions for Missing Ranges.
// Memory Usage: 8.6 MB, less than 66.67% of C++ online submissions for Missing Ranges.
// time complexity: O(n)
// space complexity: O(1)