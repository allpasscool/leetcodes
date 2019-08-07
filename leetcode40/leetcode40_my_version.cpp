class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> output;
        sort(candidates.begin(), candidates.end());
        
        for(int i = 0; i < candidates.size(); i ++) {
            vector<int> new_list;
            
            if (candidates[i] > target) {
                continue;
            } else if (candidates[i] == target) {
                output.push_back(vector<int> {candidates[i]});
                continue;
            } else if (i > 0 && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            new_list.push_back(candidates[i]);
            
            for (int j = i + 1; j < candidates.size(); j++) {
                if(j > i + 1 && candidates[j] == candidates[j - 1]) {
                    continue;
                }
                
                if (candidates[j] == target - candidates[i]) {
                    new_list.push_back(candidates[j]);
                    output.push_back(new_list);
                    new_list.pop_back();
                } else if (candidates[j] < target - candidates[i]) {
                    new_list.push_back(candidates[j]);
                    combinationSum2(candidates, target - candidates[i] - candidates[j], j + 1, new_list, output);
                    new_list.pop_back();
                }
            }
        }
        
        sort(output.begin(), output.end());
        output.erase( unique(output.begin(), output.end()), output.end());
        
        return output;
    }
    
private:
    void combinationSum2(vector<int>& candidates, int target, int start, vector<int>& new_list, vector<vector<int>>& output) {
        if (start < candidates.size()) {
            if (candidates[start] == target) {
                new_list.push_back(candidates[start]);
                output.push_back(new_list);
                new_list.pop_back();
                combinationSum2(candidates, target, start + 1, new_list, output);
            } else if (candidates[start] < target) {
                new_list.push_back(candidates[start]);
                combinationSum2(candidates, target - candidates[start], start + 1, new_list, output);
                new_list.pop_back();
                combinationSum2(candidates, target, start + 1, new_list, output);
            } else {
                combinationSum2(candidates, target, start + 1, new_list, output);
            }
        }
    }
};
// Runtime: 16 ms, faster than 34.54% of C++ online submissions for Combination Sum II.
// Memory Usage: 12.4 MB, less than 10.60% of C++ online submissions for Combination Sum II.
// time complexity: O(nlogn + 2^n), #candidates = n, target = t
// space complexity: O(n^2)