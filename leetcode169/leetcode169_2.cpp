class Solution {
public:
    int majorityElement(vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }
private:
    int countInRange(vector<int>& nums, int num, int lo, int hi) {
        int count = 0;
        for (int i = lo; i <= hi; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        
        return count;
    }
    
    int majorityElementRec(vector<int>& nums, int lo, int hi) {
        // base case; the only element in an array of size 1 is the majority element
        if (lo == hi) {
            return nums[lo];
        }
        
        // recurse on left and right halves of this slice.
        int mid = (hi - lo) / 2 + lo;
        int left = majorityElementRec(nums, lo, mid);
        int right = majorityElementRec(nums, mid + 1, hi);
        
        // If the two halves agree on the majority element, return it
        if (left == right) {
            return left;
        }
        
        // otherwise, count each element and return the "winner".
        int leftCount = countInRange(nums, left, lo, hi);
        int rightCount = countInRange(nums, right, lo, hi);
        
        return leftCount > rightCount ? left : right;
    }
};
// Runtime: 24 ms, faster than 47.09% of C++ online submissions for Majority Element.
// Memory Usage: 11 MB, less than 96.97% of C++ online submissions for Majority Element.
// time complexity: O(n logn) log n recursion, each recursion O(n)  
// space ceomplxeity: O(logn)