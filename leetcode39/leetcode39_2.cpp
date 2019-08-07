class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        
        vector<vector<vector<int>>> dp;
        
        for (int i = 1; i <= target; i ++) {// run through all targets from 1 to target
            vector<vector<int>> new_list;
            
            // run through all candidates <= i
            for (int j = 0; j < candidates.size() && candidates[j] <= target; j++) {
                // special case when current target equals to current candidate
                if (i == candidates[j]) {
                    new_list.push_back(vector<int> {candidates[j]});
                } else if (i > candidates[j]){// if current candidate is less than current target, then use previous result
                    for (vector<int> pre_list: dp[i-candidates[j]-1]) {
                        if (candidates[j] <= pre_list[0]) {
                            vector<int> tmp;
                            tmp.push_back(candidates[j]);
                            tmp.insert(tmp.end(), pre_list.begin(), pre_list.end());
                            new_list.push_back(tmp);
                        }
                    }
                }
            }
            dp.push_back(new_list);
        }
        
        return dp[target-1];
    }
};
// Runtime: 44 ms, faster than 22.25% of C++ online submissions for Combination Sum.
// Memory Usage: 18.9 MB, less than 15.60% of C++ online submissions for Combination Sum.
// time complexity: O(#candidates * target ^ 2)
// space complexity: O(target ^ 2)