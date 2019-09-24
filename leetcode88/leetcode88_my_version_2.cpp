class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        // put nums1 to the back
        for (int i = m + n - 1; i >= n; i--) {
            nums1[i] = nums1[i - n];
        }
        
        int pos1 = n, pos2 = 0;
        int pos = 0;
        
        // if m is 0, just put nums2 into nums1
        // if m is not 0
        if (m != 0) {
            while (pos < m + n && pos1 < m + n && pos2 < n) {
                if (nums1[pos1] <= nums2[pos2])
                    nums1[pos++] = nums1[pos1++];
                else 
                    nums1[pos++] = nums2[pos2++];
            }
        }
        
        // since the the end of nums1 is nums1
        // if nums1 have numbers left, it is correct
        // we don't need to handle it
        // we only need to handle if nums2 has left numbers
        while (pos2 < n)
            nums1[pos++] = nums2[pos2++];
    }
};

// Runtime: 4 ms, faster than 84.06% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 8.7 MB, less than 82.61% of C++ online submissions for Merge Sorted Array.
// time complexity: O(n + m)
// space complexity: O(1)