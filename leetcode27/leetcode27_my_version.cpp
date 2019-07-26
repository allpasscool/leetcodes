class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0){
            return 0;
        }
        
        int save = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[save] = nums[i];
                save++;
            }
        }
        
        return save;
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Element.
// Memory Usage: 8.6 MB, less than 41.96% of C++ online submissions for Remove Element.
// time complexity: O(n)
// space complexity: O(1)