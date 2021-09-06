class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        return quickSelect(nums, 0, n - 1, n - k);
    }
    
    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        int index = partition(nums, left, right);
        
        if (index == k)
        {
            return nums[index];
        }
        else if (index > k)
        {
            return quickSelect(nums, left, index - 1, k);
        }
        // index < k
        else
        {
            return quickSelect(nums, index + 1, right, k);
        }
    }
    
    int partition(vector<int>& nums, int left, int right)
    {
        int pivot = nums[right];
        int j = left;
        
        for (int i = left; i < right; i++)
        {
            if (nums[i] < pivot)
            {
                swap(nums[i], nums[j]);
                j++;
            }
        }
        
        swap(nums[j], nums[right]);
        return j;
    }
};

// Runtime: 104 ms, faster than 12.96% of C++ online submissions for Kth Largest Element in an Array.
// Memory Usage: 10 MB, less than 83.95% of C++ online submissions for Kth Largest Element in an Array.
// time complexity: O(n)
// space complexity: O(1)