class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0){
            return 0;
        }
        int save = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] != nums[i]){
                nums[save] = nums[i];
                save++;
            }
        }
        
        return save;
    }
};
// Runtime: 20 ms, faster than 93.97% of C++ online submissions for Remove Duplicates from Sorted Array.
// Memory Usage: 9.8 MB, less than 80.84% of C++ online submissions for Remove Duplicates from Sorted Array.
// time complexity: O(n)
// space complexity: O(1)