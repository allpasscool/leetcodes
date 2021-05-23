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
                backtracking(candidates, target - candidates[i], ans, cur, i);
            }
        }
        
        return ans;
    }
    
    private void backtracking(int[] candidates, int remain, List<List<Integer>> ans, List<Integer> cur, int start_index)
    {
        // candidates in cur are too big
        if (remain < 0)
        {
            return;
        }
        // find a valid answer
        else if (remain == 0)
        {
            ans.add(new ArrayList<Integer>(cur));
            return;
        }
        
        // try all candidates
        for (int i = start_index; i < candidates.length; i++)
        {
            // add candidate
            cur.add(candidates[i]);
            // find next candidate
            backtracking(candidates, remain - candidates[i], ans, cur, i);
            // remove candidate
            cur.remove(cur.size() - 1);
        }
    }
}

// Runtime: 4 ms, faster than 47.92% of Java online submissions for Combination Sum.
// Memory Usage: 38.7 MB, less than 96.79% of Java online submissions for Combination Sum.
// time complexity: O(N^(T/M+1))
// Let N be the number of candidates, T be the target value, and M be the minimal value among the candidates.
// space complexity: O(T/M)