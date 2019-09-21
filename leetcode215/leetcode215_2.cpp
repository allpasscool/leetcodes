class Solution {
public:
    // int partition(vector<int>& nums, int left, int right) {
    int partition(int left, int right) {
        // int x = nums[right] , i = left;
        int x = numbers[right] , i = left;
        for (int j = left; j <= right - 1; j++) {
            // if (nums[j] <= x) {
            //     swap(nums[i], nums[j]);
            //     i++;
            // }
            if (numbers[j] <= x) {
                swap(numbers[i], numbers[j]);
                i++;
            }
        }
        // swap(nums[i], nums[right]);
        swap(numbers[i], numbers[right]);
        return i;
    }
    
    // int kthSmallest(vector<int>& nums, int left, int right, int k) {
    int kthSmallest(int left, int right, int k) {
        if (k > 0 && k <= right - left + 1) {
            // int index = partition(nums, left, right);
            int index = partition(left, right);
            
            if (index - left == k - 1) {
                // return nums[index];
                return numbers[index];
            }
            else if (index - left > k - 1) {
                // return kthSmallest(nums, left, index - 1, k);
                return kthSmallest(left, index - 1, k);
            }
            else {
                // return kthSmallest(nums, index + 1, right, k - index + left - 1);
                return kthSmallest(index + 1, right, k - index + left - 1);
            }
        }
        
        return INT_MAX;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        numbers = nums;
        
        // return kthSmallest(nums, 0, n - 1, n - k + 1);
        return kthSmallest(0, n - 1, n - k + 1);
    }
private:
    vector<int> numbers;
};

// Runtime: 64 ms, faster than 15.71% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 11 MB, less than 6.06% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(n) in average O(n^2) worst case
// space complexity: O(1)