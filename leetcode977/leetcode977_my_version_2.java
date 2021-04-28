class Solution {
    public int[] sortedSquares(int[] nums) {
        for (int i = 0; i < nums.length; i++) {
            nums[i] *= nums[i];
        }
        
        int n = nums.length;
        int[] ans = new int[n];
        
        int p1 = 0, p2 = n - 1;
        // pos for ans
        int pos = n - 1;
        
        while (p1 <= p2) {
            if (nums[p1] < nums[p2]){
                ans[pos] = nums[p2];
                p2--;
            }
            else {
                ans[pos] = nums[p1];
                p1++;
            }
            pos--;
        }
        
        return ans;
    }
}

// Runtime: 1 ms, faster than 100.00% of Java online submissions for Squares of a Sorted Array.
// Memory Usage: 40.8 MB, less than 40.01% of Java online submissions for Squares of a Sorted Array.
// time complexity: O(n)
// space complexity: O(N) if you take output into account and O(1) otherwise.