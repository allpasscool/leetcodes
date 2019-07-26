class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        
        int i = 0, n = nums.size();
        while(i < n){
            if(nums[i] == val){
                nums[i] = nums[n - 1];
                //reduce array size by one
                n--;
            } else{
                i++;
            }
        }
        
        return n;
    }
};
// Runtime: 4 ms, faster than 75.99% of C++ online submissions for Remove Element.
// Memory Usage: 8.6 MB, less than 40.45% of C++ online submissions for Remove Element.
// time complexity: O(n)
// space complexity: O(1)