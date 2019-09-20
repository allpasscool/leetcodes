class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int take = 0, avoid = 0;
        
        if (n == 0) {
            return 0;
        }
        else if (n == 1) {
            return nums[0];
        }
        else if (n == 2) {
            return max(nums[0], nums[1]);
        }
        
        for (int i = 0; i < n; i++) {
            int takei = avoid + nums[i];
            int avoidi = max(take, avoid);
            avoid = avoidi;
            take = takei;
        }
        
        return max(take, avoid);
    }
};

// Runtime: 4 ms, faster than 57.10% of C++ online submissions for House Robber.
// Memory Usage: 8.5 MB, less than 92.45% of C++ online submissions for House Robber.
// time complexity: O(n)
// space complexity: O(1)