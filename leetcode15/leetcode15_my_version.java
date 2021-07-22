// Runtime: 19 ms, faster than 81.54% of Java online submissions for 3Sum.
// Memory Usage: 43.1 MB, less than 60.80% of Java online submissions for 3Sum.
// time complexity: O(n^2)
// space complexity: O(1)
class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        
        Arrays.sort(nums);
        int first = 0;
        while (first < nums.length - 2)
        {
            int target = -nums[first];
            int second = first + 1;
            int third = nums.length - 1;
            
            while (second < third)
            {
                if (nums[second] + nums[third] == target)
                {
                    ans.add(Arrays.asList(nums[first], nums[second], nums[third]));
                    second++;
                    third--;
                    
                    // ignore same value
                    // 1 1 2 2 3 4 5 5
                    // f   s         t
                    // f       s t
                    while (second < nums.length - 1 && nums[second - 1] == nums[second])
                        second++;
                    while (third > second && nums[third + 1] == nums[third])
                        third--;
                }
                else if (nums[second] + nums[third] < target)
                {
                    second++;
                }
                else
                {
                    third--;
                }
            }
            
            first++;
            // ignore same value
            // 1 1 2 2 3 4 5 5
            // f   
            //     f
            while (first < nums.length - 2 && nums[first - 1] == nums[first])
                first++;
        }
        
        return ans;
    }
}