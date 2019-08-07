class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> combination;
        combinationSum(candidates, target, res, combination, 0);
        
        return res;
    }
private:
    void combinationSum(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& combination, int begin) {
        if (!target) {
            res.push_back(combination);
            return;
        } 
        
        for (int i = begin; i < candidates.size() && target >= candidates[i]; i++) {
            combination.push_back(candidates[i]);
            combinationSum(candidates, target - candidates[i], res, combination, i);
            combination.pop_back();
        }
    }
};
// Runtime: 8 ms, faster than 98.17% of C++ online submissions for Combination Sum.
// Memory Usage: 9.3 MB, less than 97.16% of C++ online submissions for Combination Sum.
// time complexity: O(#candidates^target)
// space complexity: O(target)