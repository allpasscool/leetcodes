class Solution {
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        backtracking(nums, ans, 0);
        
        return ans;
    }
    
    private void backtracking(int[] nums, List<List<Integer>> ans, int index)
    {
        // if all integers are used up
        if (index == nums.length)
        {
            List<Integer> arrL = new ArrayList<Integer>(nums.length);
            for (int i = 0; i < nums.length; i++)
            {
                arrL.add(nums[i]);
            }
            
            ans.add(arrL);
            return;
        }
        
        for (int i = index; i < nums.length; i++)
        {
            // swap nums[index] and nums[i]
            swap(nums, index, i);
            // use next integers to complete the permutations
            backtracking(nums, ans, index + 1);
             // backtrack
            swap(nums, index, i);
        }
    }
    
    private void swap(int[] nums, int p1, int p2)
    {
        int tmp = nums[p1];
        nums[p1] = nums[p2];
        nums[p2] = tmp;
    }
}


// Runtime: 0 ms, faster than 100.00% of Java online submissions for Permutations.
// Memory Usage: 39.1 MB, less than 56.16% of Java online submissions for Permutations.
// time complexity: O(n!)
// space complexity: O(n!)
