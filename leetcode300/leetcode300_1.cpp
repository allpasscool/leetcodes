class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        vector<int> tail(n, 0);
        int length = 1;
        tail[0] = nums[0];
        
        for (int i = 1; i < n; ++i) {
            if (nums[i] < tail[0])
                tail[0] = nums[i];
            else if (nums[i] > tail[length - 1])
                tail[length++] = nums[i];
            // nums[i] will be end candidate of existing subsequence
            // or throw away larger elements in all longest increasing subsequence
            // to make room for upcoming greater elements than nums[i]
            // (and also nums[i] would have already appeared in one of LIS
            // Identify the location and replace it)            
            else {
                tail[CeilIndex(tail, -1, length - 1, nums[i])] = nums[i];
            }
        }
        
        return length;
    }
private:
    // binary search to find the index where tail[i] to be replaced
    int CeilIndex (vector<int>& tail, int left, int right, int key) {
        while (left + 1 < right) {
            int m = left + (right - left) / 2;
            if (tail[m] >= key)
                right = m;
            else
                left = m;
        }
        
        return right;
    }
};

// Runtime: 4 ms, faster than 90.52% of C++ online submissions for Longest Increasing Subsequence.
// Memory Usage: 8.8 MB, less than 42.19% of C++ online submissions for Longest Increasing Subsequence.
// time complexity: O(n log n)
// space complexity: O(n)
// https://www.geeksforgeeks.org/longest-monotonically-increasing-subsequence-size-n-log-n/