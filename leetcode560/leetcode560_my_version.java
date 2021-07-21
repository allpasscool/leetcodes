class Solution {
    public int subarraySum(int[] nums, int k) {
        Map<Integer, Integer> accumulatedSum = new HashMap<>();
        int sum = 0;
        int ans = 0;
        // means that if we want to find accumulate sum == 0, sum now is k
        accumulatedSum.put(0, 1);
        
        for (int num : nums)
        {
            sum += num;
            // sum(i,j) =sum(0, j) - sum(0, i)
            if (accumulatedSum.containsKey(sum - k))
                ans += accumulatedSum.get(sum - k);
            
            accumulatedSum.put(sum, accumulatedSum.getOrDefault(sum, 0) + 1);
        }
        
        return ans;
    }
}

// Runtime: 18 ms, faster than 73.54% of Java online submissions for Subarray Sum Equals K.
// Memory Usage: 41.4 MB, less than 68.32% of Java online submissions for Subarray Sum Equals K.
// time complexity: O(n)
// space complexity: O(n)
// same as Solution 3