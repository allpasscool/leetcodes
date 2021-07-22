// Runtime: 1 ms, faster than 100.00% of Java online submissions for Product of Array Except Self.
// Memory Usage: 52.4 MB, less than 30.92% of Java online submissions for Product of Array Except Self.
// time complexity: O(n)
// space complexity: O(n)

class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] left = new int[nums.length];
        int[] right = new int[nums.length];
        int[] ans = new int[nums.length];
        int sum = 1;
        
        for (int i = 0 ; i < nums.length; i++)
        {
            sum *= nums[i];
            left[i] = sum;
        }
        
        sum = 1;
        for (int i = nums.length - 1 ; i >= 0; i--)
        {
            sum *= nums[i];
            right[i] = sum;
        }
        
        for (int i = 0; i < nums.length; i++)
        {
            ans[i] = 1;
            
            if (i > 0)
                ans[i] *= left[i - 1];
            
            if (i < nums.length - 1)
                ans[i] *= right[i + 1];
        }
        
        return ans;
    }
}