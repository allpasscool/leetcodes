class Solution {
public:
    void backtrack(int n, vector<int>& nums,
                  vector<vector<int>>& output,
                  int first) {
        // if all integers are used up
        if (first == n) {
            output.push_back(vector<int> {nums});
        }
        
        for (int i = first; i < n; i++) {
            // place i-th integer first
            // in the current permutation
            swap(nums[first], nums[i]);
            // use next integers to complete the permutations
            backtrack(n, nums, output, first + 1);
            // backtrack
            swap(nums[first], nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        // init output vector
        vector<vector<int>> output;
        
        int n = nums.size();
        backtrack(n, nums, output, 0);
        return output;
    }
};
// Runtime: 12 ms, faster than 66.93% of C++ online submissions for Permutations.
// Memory Usage: 9.2 MB, less than 94.03% of C++ online submissions for Permutations.
// time complexity: O(N * N!)
// space complexity: O(N!)