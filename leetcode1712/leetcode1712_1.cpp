class Solution {
public:
    int waysToSplit(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<int> prefix_sum(n, 0);
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            prefix_sum[i] = sum;
        }
//         partial_sum(begin(nums), end(nums), begin(nums));
        
        // left_end means the last index of left subarray
        // mid_start means the mid subarray from this index to right_last - 1 satisfy the restriction
        // right_last means with the left_end, this is the last index right subarray has to start
        // i = left_end, j = mid_start, k = right_last
        for (int left_end = 0, mid_start = 1, right_last = 2; left_end < n - 2; ++left_end) {
            
            // while(j <= i || (j < n - 1 && prefix_sum[j] - prefix_sum[i] < prefix_sum[i]))
            //     ++j;
            mid_start = max(left_end + 1, mid_start);
            while((mid_start < n - 1 
                   && prefix_sum[mid_start] - prefix_sum[left_end] < prefix_sum[left_end])) {
                ++mid_start;
            }
            
            // while(k <= j || (k < n && prefix_sum[k - 1] - prefix_sum[i] <= prefix_sum[n - 1] - prefix_sum[k - 1]))
            //     ++k;
            right_last = max(mid_start + 1, right_last);
            while(right_last < n 
                  && prefix_sum[right_last - 1] - prefix_sum[left_end] <= prefix_sum[n - 1] - prefix_sum[right_last - 1]) {
                ++right_last;
            }
            
            ans = (ans + right_last - mid_start - 1) % 1000000007;
            
            // cout << j << " " << k << endl;
            
            // If mid < right,  then break
            // This won't work since mid might decrease when left increase
            // In this case mid > right but later mid <= right
            // Therefore, we can't do early break
            // if (prefix_sum[j] - prefix_sum[left_end] > prefix_sum[n - 1] - prefix_sum[j]) {
            //     break;
            // }
            
        }
        
        return ans;
    }
};

// Runtime: 220 ms, faster than 97.15% of C++ online submissions for Ways to Split Array Into Three Subarrays.
// Memory Usage: 85 MB, less than 70.36% of C++ online submissions for Ways to Split Array Into Three Subarrays.
// time complexity: O(n)
// space complexity: O(1)

// https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/discuss/999257/C%2B%2BJavaPython-O(n)-with-picture
// int waysToSplit(vector<int>& nums) {
//     int res = 0, sz = nums.size();
//     partial_sum(begin(nums), end(nums), begin(nums));
//     for (int i = 0, j = 0, k = 0; i < sz - 2; ++i) {
//         while (j <= i || (j < sz - 1 && nums[j] < nums[i] * 2))
//             ++j;
//         while (k <= j || ( k < sz && nums[k - 1] - nums[i] <= nums[sz - 1] - nums[k - 1]))
//             ++k;
//         res = (res + k - j - 1) % 1000000007;
//         // cout << i << endl << j << endl << k;
//     }
//     return res;
// }