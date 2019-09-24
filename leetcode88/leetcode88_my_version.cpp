class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for (int i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }
        
        sort(nums1.begin(), nums1.end());
    }
};

// Runtime: 4 ms, faster than 84.06% of C++ online submissions for Merge Sorted Array.
// Memory Usage: 8.8 MB, less than 65.22% of C++ online submissions for Merge Sorted Array.
// time complexity: O(mn log (mn))
// space complexity: O(1)