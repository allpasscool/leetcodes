class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<int> tmp;
        vector<vector<int>> output;
        
        combinationSum2(candidates, target, tmp, output, 0);
        
        return output;
    }
    
private:
    void combinationSum2(vector<int>& candidates, int target, vector<int>& tmp, vector<vector<int>>& output, int start) {
        if (target == 0) {
            output.push_back(tmp);
        } else if (target > 0) {
            for (int i = start; i < candidates.size(); i++) {
                //escape duplicate number
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                
                tmp.push_back(candidates[i]);
                combinationSum2(candidates, target - candidates[i], tmp, output, i + 1);
                tmp.pop_back();
            }
        }
    }
};
// Runtime: 12 ms, faster than 52.57% of C++ online submissions for Combination Sum II.
// Memory Usage: 8.9 MB, less than 100.00% of C++ online submissions for Combination Sum II.
// time complexity: O(nlogn + n^target), #candidates = n
// space complexity: O(n^target)