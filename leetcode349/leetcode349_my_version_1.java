class Solution {
    public int[] intersection(int[] nums1, int[] nums2) {
        HashSet<Integer> n1_set = new HashSet<>();
        HashSet<Integer> n2_set = new HashSet<>();
        
        int n1 = nums1.length, n2 = nums2.length;
        
        for (int i = 0; i < n1; i++) {
            if (!n1_set.contains(nums1[i])) {
                n1_set.add(nums1[i]);
            }
        }
        
        for (int i = 0; i < n2; i++) {
            if (!n2_set.contains(nums2[i]) && n1_set.contains(nums2[i])) {
                n2_set.add(nums2[i]);
            }
        }
        
        int[] ans = new int[n2_set.size()];
        
        int pos = 0;
        for (Integer num : n2_set) {
            ans[pos] = num;
            pos++;
        }
        
        return ans;
    }
}

// Runtime: 2 ms, faster than 93.21% of Java online submissions for Intersection of Two Arrays.
// Memory Usage: 39.3 MB, less than 30.89% of Java online submissions for Intersection of Two Arrays.
// time complexity: O(m + n)
// space complexity: O(m + n)