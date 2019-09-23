class Solution {
public:
    int countArrangement(int N) {
        vector<int> nums(N, 0);
        
        for (int i = 1; i <= N; ++i) {
            nums[i - 1] = i;
        }
        
        permute(nums, 0);
        
        return count;
    }
    
    void permute (vector<int>& nums, int left) {
        if (left == nums.size()) {
            ++count;
        }
        
        for (int i = left; i < nums.size(); ++i) {
            swap(nums[i], nums[left]);
            if (nums[left] % (left + 1) == 0 || (left + 1) % nums[left] == 0)
                permute(nums, left + 1);
            swap(nums[i], nums[left]);
        }
    }
    
private:
    int count = 0;
};

// Runtime: 88 ms, faster than 69.39% of C++ online submissions for Beautiful Arrangement.
// Memory Usage: 8.2 MB, less than 100.00% of C++ online submissions for Beautiful Arrangement.
// time complexity: O(k), k refers to the number of valid permutations
// space complexity: O(n)