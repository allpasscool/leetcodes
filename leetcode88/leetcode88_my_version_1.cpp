class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> output(m + n, 0);
        
        int pos1 = 0, pos2 = 0;
        int pos = 0;
        
        while (pos1 < m && pos2 < n) {
            if (nums1[pos1] <= nums2[pos2]) {
                output[pos++] = nums1[pos1++];
            }
            else {
                output[pos++] = nums2[pos2++];
            }
        }
        
        while (pos1 < m)
            output[pos++] = nums1[pos1++];
        while (pos2 < n)
            output[pos++] = nums2[pos2++];
        
        nums1 = output;
    }
};

// Runtime: 4 ms, faster than 84.06% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 8.6 MB, less than 91.30% of C++ online submissions for Merge Sorted Array.
// time complexity: O(m + n)
// space complexity: O(m + n)