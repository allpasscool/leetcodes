class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // unordered_map<int, int> hashmap;
        vector<int> hashmap(n + 1);
        int prefix_count = 0;
        
        ++hashmap[0];
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 2 == 1) {
                ++prefix_count;
            }
            
            ++hashmap[prefix_count];
        }
        
        int ans = 0;
        for (int i = k; i <= prefix_count; ++i) {
            ans += hashmap[i] * hashmap[i - k];
        }
        
        return ans;
    }
    
};


// Runtime: 184 ms, faster than 62.50% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 19.7 MB, less than 100.00% of C++ online submissions for Count Number of Nice Subarrays.
// time complexity: O(n)
// space complexity: O(n)