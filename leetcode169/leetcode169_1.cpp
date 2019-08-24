class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        
        if (n == 0) {
            return 0;
        }
        
        while (true) {
            int candidate = nums[pickCandidate(0, n)];
            if (countOccurences(nums, candidate) > n / 2) {
                return candidate;
            }
        }
        
        return 0;
    }
    
private:
    int pickCandidate(int min_n, int max_n) {
        int r = rand();
        return r % (max_n - min_n) + min_n;
    }
    
    int countOccurences(vector<int>& nums, int num) {
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        
        return count;
    }
};
// Runtime: 16 ms, faster than 96.67% of C++ online submissions for Majority Element.
// Memory Usage: 11.1 MB, less than 86.36% of C++ online submissions for Majority Element.
// time complexity: O(infinity)
// space complexity: O(1)