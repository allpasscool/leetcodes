class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int nums_size = nums.size();
        
        if(nums_size <= 1){
            return;
        }
        
        //in descending order
        bool is_descending = true;
        
        for(int i = nums_size - 1; i >= 1; i--){
            if(nums[i] > nums[i-1]){
                is_descending = false;
                
                //get next permutation from nums[i-1] to the end
                int num_start_for_next_permutation = INT_MAX, next_pos = i;
                for(int j = i; j < nums_size; j++){
                    if(nums[j] <= num_start_for_next_permutation && nums[j] > nums[i-1]){
                        num_start_for_next_permutation = nums[j];
                        next_pos = j;
                    }
                }
                
                swap(nums[i-1], nums[next_pos]);
                reverse(nums.begin() + i, nums.end());
                
                return;
            }
        }
        
        //is descending order, than change to ascending order
        if(is_descending){
            reverse(nums.begin(), nums.end());
        }
        
        return;
    }
};
// Runtime: 4 ms, faster than 99.05% of C++ online submissions for Next Permutation.
// Memory Usage: 8.6 MB, less than 54.83% of C++ online submissions for Next Permutation.
// time complexity: O(n)
// space complexity: O(1)