class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        
        for (int i = 0; i < candidates.length; i++) {
            // not too big
            if (candidates[i] <= target)
            {
                List<Integer> cur = new ArrayList<>();
                // add this candidate
                cur.add(candidates[i]);
                backtracking(candidates, target, ans, cur, candidates[i], i);
            }
        }
        
        return ans;
    }
    
    private void backtracking(int[] candidates, int target, List<List<Integer>> ans, List<Integer> cur, int sum, int start_index)
    {
        // candidates in cur are too big
        if (sum > target)
        {
            return;
        }
        // find a valid answer
        else if (sum == target)
        {
            ans.add(new ArrayList<Integer>(cur));
            return;
        }
        
        // try all candidates
        for (int i = start_index; i < candidates.length; i++)
        {
            // add candidate
            cur.add(candidates[i]);
            sum += candidates[i];
            // find next candidate
            backtracking(candidates, target, ans, cur, sum, i);
            // remove candidate
            sum -= candidates[i];
            cur.remove(cur.size() - 1);
        }
    }
}

// Runtime: 4 ms, faster than 47.92% of Java online submissions for Combination Sum.
// Memory Usage: 38.7 MB, less than 96.79% of Java online submissions for Combination Sum.
// time complexity: O(N^(T/M+1))
// Let N be the number of candidates, T be the target value, and M be the minimal value among the candidates.
// space complexity: O(T/M)