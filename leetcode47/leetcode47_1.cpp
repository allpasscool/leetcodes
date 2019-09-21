class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        permutation(nums, 0, output);
        
        return output;
    }
    
    void permutation(vector<int> nums, int start, vector<vector<int>>& output) {
        if (start == nums.size() - 1) {
            output.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            if (start != i && nums[i] == nums[start]) {
                continue;
            }
            
            swap(nums[start], nums[i]);
            permutation(nums, start + 1, output);
        }
    }
};

// Runtime: 24 ms, faster than 68.57% of C++ online submissions for Permutations II.
// Memory Usage: 10.3 MB, less than 52.38% of C++ online submissions for Permutations II.
// time complexity: O(n!)
// space complexity: O(n!)