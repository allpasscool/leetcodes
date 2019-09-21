class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        
        permutation(nums, 0, output);
        
        return output;
    }
    
    void permutation(vector<int>& nums, int start, vector<vector<int>>& output) {
        if (start == nums.size() - 1) {
            output.push_back(nums);
            return;
        }
        
        for (int i = start; i < nums.size(); ++i) {
            
            int j = i - 1;
            // judege whether nums[i] and nums[start ... i-1] are equal
            // if we got it, that means all the permutation with nums[i] at start
            // has been visited
            while (j >= start && nums[j] != nums[i]) {
                --j;
            }
            
            if (j >= start) {
                continue;
            }
            
            swap(nums[start], nums[i]);
            permutation(nums, start + 1, output);
            swap(nums[start], nums[i]);
        }
    }
};

// Runtime: 20 ms, faster than 94.96% of C++ online submissions for Permutations II.
// Memory Usage: 9.7 MB, less than 100.00% of C++ online submissions for Permutations II.
// time complexity: O(n!)
// space complexity: O(n!)