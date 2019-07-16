class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> output;
        
        for(int i = 0; i < nums.size();){
            
            int target = -nums[i];
            int left = i + 1, right = nums.size() - 1;
            
            while(left < right){
                int sum = nums[left] + nums[right];
                
                if(sum < target){
                    //ignore duplicate left
                    do{
                        left++;
                    }while(left < right && nums[left-1] == nums[left]);
                }
                else if(sum > target){
                    //ignore duplicate right
                    do{
                        right--;
                    }while(right > left && nums[right+1] == nums[right]);
                }
                else{
                    output.push_back(vector<int> {nums[i], nums[left], nums[right]});
                    //ignore duplicate left
                    do{
                        left++;
                    }while(left < right && nums[left-1] == nums[left]);
                    //ignore duplicate right
                    do{
                        right--;
                    }while(right > left && nums[right+1] == nums[right]);
                }
            }
            
            //ignore duplicate beginning
            do{
                i++;
            }while(i < nums.size() && nums[i-1] == nums[i]);
        }
        
        return output;
    }
};
// Runtime: 96 ms, faster than 86.96% of C++ online submissions for 3Sum.
// Memory Usage: 14.5 MB, less than 90.74% of C++ online submissions for 3Sum.
// time complexity: O(n log n + n ^ 2)
// space complexity: O(n^3)