class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> index;
        vector<int> output;
        if (nums.empty())
            return output;
        
        // insert k - 1 elements
        for (int i = 0; i < k - 1; ++i) {
            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
        }
        
        for (int i = k - 1; i < nums.size(); ++i) {
            while (!index.empty() && nums[i] >= nums[index.back()])
                index.pop_back();
            index.push_back(i);
            output.push_back(nums[index.front()]);
            if (i - k + 1 >= index.front())
                index.pop_front();
        }
        
        return output;
    }
};


// Runtime: 56 ms, faster than 85.29% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13.2 MB, less than 63.93% of C++ online submissions for Sliding Window Maximum.
// time complexity: O(n)
// space complexity: O(k)

// Author: Huahua
// Running time: 65 ms
// class Solution {
// public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     deque<int> index;
//     vector<int> ans;
        
//     for (int i = 0; i < nums.size(); ++i) {
//       while (!index.empty() && nums[i] >= nums[index.back()]) index.pop_back();
//       index.push_back(i);      
//       if (i - k + 1 >= 0) ans.push_back(nums[index.front()]);
//       if (i - k + 1 >= index.front()) index.pop_front();
//     }
//     return ans;
//   }
// };
// http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/
