class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        if (nums.size() == 0)
            return output;
        
        
        for (int i = 0; i < nums.size() - k + 1; ++i) {
            output.push_back(*max_element(nums.begin() + i, nums.begin() + i + k));
        }
        
        return output;
    }
};


// Runtime: 156 ms, faster than 5.34% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 12.8 MB, less than 96.72% of C++ online submissions for Sliding Window Maximum.
// time complexity: O(n * k)
// space complexity: O(1)

// Author: Huahua
// Running time: 180 ms
// class Solution {
// public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {    
//     vector<int> ans;
//     for (int i = k - 1; i < nums.size(); ++i) {
//       ans.push_back(*max_element(nums.begin() + i - k + 1, nums.begin() + i + 1));
//     }
//     return ans;
//   }
// };
// http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
