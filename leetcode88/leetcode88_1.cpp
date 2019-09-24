class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = m - 1, pos2 = n - 1;
        int pos = m + n - 1;
        
        
        while (pos >= 0 && pos1 >= 0 && pos2 >= 0) {
            if (nums1[pos1] >= nums2[pos2])
                nums1[pos--] = nums1[pos1--];
            else 
                nums1[pos--] = nums2[pos2--];
        }
        
        // since the the start of nums1 is nums1
        // if nums1 have numbers left, it is correct
        // we don't need to handle it
        // we only need to handle if nums2 has left numbers
        while (pos2 >= 0)
            nums1[pos--] = nums2[pos2--];
    }
};

// Runtime: 4 ms, faster than 84.06% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 8.7 MB, less than 80.43% of C++ online submissions for Merge Sorted Array.
// time complexity: O(n + m)
// space complexity: O(1)