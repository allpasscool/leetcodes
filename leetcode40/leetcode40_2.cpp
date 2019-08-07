class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        set<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        vector<int> curr;
        
        dfs(candidates, target, 0, ans, curr);
        
        return vector<vector<int>> (ans.begin(), ans.end());
    }
    
    void dfs(const vector<int>& candidates,
            int target, int s,
            set<vector<int>>& ans,
            vector<int>& curr) {
        if (target == 0) {
            ans.insert(curr); // set won't insert duplicate item
            return;
        }
        
        for (int i = s; i < candidates.size(); i++) {
            int num = candidates[i];
            
            if (num > target) {
                return;
            }
            
            curr.push_back(num);
            dfs(candidates, target - num, i + 1, ans, curr);
            curr.pop_back();
        }
    }
};
// Runtime: 8 ms, faster than 84.71% of C++ online submissions for Combination Sum II.
// Memory Usage: 9.2 MB, less than 53.03% of C++ online submissions for Combination Sum II.
// time complexity: O(2^n)
// space complexity: O(k * n), k is the number of result