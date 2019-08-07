class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        int sum = 0;
        
        vector<int> last_candidates = candidates;
        
        //try all candidates
        for (int i = 0; i < candidates.size(); i++) {
            
            //candidate < target
            if (candidates[i] < target) {
                vector<vector<int>> tmp;
                
                //if this candidate is invloved
                tmp = combinationSum(last_candidates, target - candidates[i]);
                
                if (tmp.size() != 0) {
                    for (int j = 0; j < tmp.size(); j++) {
                        tmp[j].insert(tmp[j].begin(), candidates[i]);
                    }
                }
                
                output.insert(output.end(), tmp.begin(), tmp.end());
            } else if (candidates[i] == target) {//candidate == target
                output.push_back(vector<int> {candidates[i]});
            }
            
            last_candidates.erase(last_candidates.begin());
        }
        
        return output;
    }
};
// Runtime: 32 ms, faster than 26.97% of C++ online submissions for Combination Sum.
// Memory Usage: 12.3 MB, less than 41.89% of C++ online submissions for Combination Sum.
// time complexity: O(#candidates^target), if candidate include 1
// space complexity: O(candidates * target)