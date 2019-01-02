class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<int> answer (2);
        for(vector<int>::size_type i = 0;
                                  i < size;
                                  i++){
            for(vector<int>::size_type j = i+1;
                                      j < size;
                                      j++){
                if(nums[i] + nums[j] == target){
                    answer[0] = i;
                    answer[1] = j;
                    return answer;
                }
                else if(nums[i] > target){
                    continue;
                }
            }
            
        }
    }
};