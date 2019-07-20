class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> output;
        
        if(nums.size() < 4){
            return output;
        }
        
        sort(nums.begin(), nums.end());
        
        
        for(int i = 0; i < nums.size() - 3;){
            for(int j = i + 1; j < nums.size() - 2;){
                int left = j + 1, right = nums.size() - 1;
                
                //this i j + 2 biggest nums < target
                if(nums[i] + nums[j] + 2 * nums[right] < target){
                    //ignore same left
                    j++;
                    while(j < nums.size() - 1 && nums[j] == nums[j-1]){
                        j++;
                    }
                    continue;
                }
                else if(nums[i] + nums[j] + 2 * nums[left] > target){//this i j + 2 smallest and bigger than nums[i] and nums[j] > target
                    break;
                }
                
                while(left < right){
                    int sum = nums[i] + nums[j] + nums[left] + nums[right];
                    
                    if(sum == target){
                        output.emplace_back(vector<int> {nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        //ignore same left
                        while(right > left && nums[left-1] == nums[left]){
                            left++;
                        }
                        
                        right--;
                        //ignore same right
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                    else if(sum < target){
                        left++;
                        //ignore same left
                        while(right > left && nums[left-1] == nums[left]){
                            left++;
                        }
                    }
                    else if(sum > target){
                        right--;
                        //ignore same right
                        while(left < right && nums[right] == nums[right+1]){
                            right--;
                        }
                    }
                }
                //ignore same left
                j++;
                while(j < nums.size() - 1 && nums[j-1] == nums[j]){
                    j++;
                }
            }
            
            
            //ignore same left
            i++;
            while(i < nums.size() - 1 && nums[i] == nums[i-1]){
                i++;
            }
        }
        
        return output;
    }
};
// Runtime: 8 ms, faster than 98.76% of C++ online submissions for 4Sum.
// Memory Usage: 9 MB, less than 85.80% of C++ online submissions for 4Sum.
// time complexity: O(n^3)
// space complexity: O(n^4)