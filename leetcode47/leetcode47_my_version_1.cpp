class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> permutation_set;
        sort(nums.begin(), nums.end());
        
        permutation(nums, 0, permutation_set);
        
        vector<vector<int>> output;
        for(auto v: permutation_set) {
            output.push_back(v);
        }
        
        return output;
    }
    
    void permutation(vector<int>& nums, int start, set<vector<int>>& permutation_set) {
        
        for (int i = start; i < nums.size(); i++) {
            if (start != i && nums[i] == nums[start]) {
                continue;
            }
            
            swap(nums[start], nums[i]);
            permutation_set.insert(nums);
            permutation(nums, start + 1, permutation_set);
            swap(nums[start], nums[i]);
        }
    }
};

// Runtime: 76 ms, faster than 13.38% of C++ online submissions for Permutations II.
// Memory Usage: 10.8 MB, less than 28.57% of C++ online submissions for Permutations II.
// time complexity: O(n!)
// space complexity: O(n!)