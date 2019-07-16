class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int output = nums[0] + nums[1] + nums[2];
        
        for(int i = 0; i < nums.size();){
            int left = i+1, right = nums.size()-1;
            
            while(left < right){
                int sum = nums[i] + nums[left] + nums[right];
                
                //find answer?
                if(sum == target){
                    return target;
                }
                else if(std::abs(target - sum) < std::abs(target - output)){
                    output = sum;
                }
                
                if(target > sum){
                    //ignore duplicate left
                    do{
                        left++;
                    }while(left < right && nums[left-1] == nums[left]);
                }
                else{
                    //ignore duplicate right
                    do{
                        right--;
                    }while(right > left && nums[right+1] == nums[right]);
                }
            }
            
            do{
                i++;
            }while(i < nums.size() && nums[i-1] == nums[i]);
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 99.52% of C++ online submissions for 3Sum Closest.
// Memory Usage: 8.7 MB, less than 61.72% of C++ online submissions for 3Sum Closest.
// time complexity: O(nlogn + n^2)
// space complexity: O(1)