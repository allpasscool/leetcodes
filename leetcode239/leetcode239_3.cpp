class MonotonicQueue {
public:
    void push(int e) {
        while (!data_.empty() && e > data_.back())
            data_.pop_back();
        data_.push_back(e);
    }
    
    void pop() {
        data_.pop_front();
    }
    
    int max() const{
        return data_.front();
    }
private:
    deque<int> data_;
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MonotonicQueue q;
        vector<int> output;
        if (nums.empty())
            return output;
        
        // insert k - 1 elements
        for (int i = 0; i < k - 1; ++i) {
            q.push(nums[i]);
        }
        
        for (int i = k - 1; i < nums.size(); ++i) {
            q.push(nums[i]);
            output.push_back(q.max());
            
            // remove the element that will be out of window
            if (nums[i - k + 1] == q.max())
                q.pop();
        }
        
        return output;
    }
};


// Runtime: 56 ms, faster than 85.29% of C++ online submissions for Sliding Window Maximum.
// Memory Usage: 13 MB, less than 83.61% of C++ online submissions for Sliding Window Maximum.
// time complexity: O(n) // at most push and pop once
// space complexity: O(k)

// Author: Huahua
// Running time: 70 ms
// class MonotonicQueue {
// public:
//   void push(int e) {
//     while(!data_.empty() && e > data_.back()) data_.pop_back();
//     data_.push_back(e);
//   } 
  
//   void pop() {
//     data_.pop_front();
//   }
  
//   int max() const { return data_.front(); }
// private:
//   deque<int> data_;
// };
 
// class Solution {
// public:
//   vector<int> maxSlidingWindow(vector<int>& nums, int k) {
//     MonotonicQueue q;
//     vector<int> ans;
        
//     for (int i = 0; i < nums.size(); ++i) {
//       q.push(nums[i]);
//       if (i - k + 1 >= 0) {
//         ans.push_back(q.max());
//         if (nums[i - k + 1] == q.max()) q.pop();
//       }      
//     }
//     return ans;
//   }
// };
// http://zxi.mytechroad.com/blog/heap/leetcode-239-sliding-window-maximum/