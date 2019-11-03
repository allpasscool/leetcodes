class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums, k) - atMost(nums, k - 1);
    }
    
private:
    // subarray has at most k odds
    int atMost(vector<int>& nums, int k) {
        int ans = 0;
        int start = 0;
        int n = nums.size();
        
        for (int end = 0; end < n; ++end) {
            if (nums[end] % 2 == 1)
                k--;
            
            while (k < 0) {
                if (nums[start] % 2 == 1) {
                    ++k;
                }
                ++start;
            }
            
            ans += end - start + 1;
        }
        
        return ans;
    }
};


// Runtime: 188 ms, faster than 37.50% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 16.4 MB, less than 100.00% of C++ online submissions for Count Number of Nice Subarrays.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/count-number-of-nice-subarrays/discuss/419378/JavaC%2B%2BPython-Sliding-Window-atMost(K)-atMost(K-1)

// int numberOfSubarrays(vector<int>& A, int k) {
//     return atMost(A, k) - atMost(A, k - 1);
// }

// int atMost(vector<int>& A, int k) {
//     int res = 0, i = 0, n = A.size();
//     for (int j = 0; j < n; j++) {
//         k -= A[j] % 2;
//         while (k < 0)
//             k += A[i++] % 2;
//         res += j - i + 1;
//     }
//     return res;
// }