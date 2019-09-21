class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minheap;
        int n = nums.size();
        const int minheap_size = n - k + 1;
        
        for (int i = 0; i < n; i++) {
            minheap.push(nums[i]);
            
            if (minheap.size() > k) {
                minheap.pop();
            }
        }
        
        return minheap.top();
    }
};

// Runtime: 12 ms, faster than 77.31% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 9.4 MB, less than 60.61% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(n log k)
// space complexity: O(k)