class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> output;
        
        if (nums.empty())
            return output;
        
        // from 0, 1, ..., k - 2
        multiset<int> window(nums.begin(), nums.begin() + k - 1);
                    
        for (int i = k - 1; i < nums.size(); ++i) {
            window.insert(nums[i]);
            output.push_back(*window.rbegin());
            
            // remove the first element
            // equal_range return pair, first is the start pos, second is the end pos + 1
            window.erase(window.equal_range(nums[i - k + 1]).first);
        }
        
        return output;
    }
};

// Runtime: 72 ms, faster than 27.25% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 18.1 MB, less than 8.20% of C++ online submissions for Sliding Window Maximum.
// time complexity: O((n - k + 1) log k)
// space complexity: O(k)

// Author: Huahua
// Running time: 82 ms
// class Solution {
// public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     vector<int> ans;
//     if (nums.empty()) return ans;
//     multiset<int> window(nums.begin(), nums.begin() + k - 1);
//     for (int i = k - 1; i < nums.size(); ++i) {
//       window.insert(nums[i]);
//       ans.push_back(*window.rbegin());
//       if (i - k + 1 >= 0)
//         window.erase(window.equal_range(nums[i - k + 1]).first);      
//     }
//     return ans;
//   }
// };
// http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/