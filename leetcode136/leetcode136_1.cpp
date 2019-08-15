class Solution {
public:
    int singleNumber(vector<int>& nums) {
        set<int> nums_set;
        
        int sum = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            nums_set.insert(nums[i]);
        }
        
        int set_sum = 0;
        for (auto i = nums_set.begin(); i != nums_set.end(); i++) {
            set_sum += 2 * (*i);
        }
        
        return set_sum - sum;
    }
};
//2∗(a+b+c)−(a+a+b+b+c)=c
// Runtime: 40 ms, faster than 5.36% of C++ online submissions for Single Number.
// Memory Usage: 11.9 MB, less than 8.64% of C++ online submissions for Single Number.
// time complexity: O(N)
// space complexity: O(N)