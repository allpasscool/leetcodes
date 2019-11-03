class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> hashmap;
        int prefix_count = 0;
        int ans = 0;
        
        ++hashmap[0];
        for (int i = 1; i <= n; ++i) {
            if (nums[i - 1] % 2 == 1) {
                ans += hashmap[prefix_count] * hashmap[prefix_count - k];
                ++prefix_count;
            }
            
            ++hashmap[prefix_count];
        }
        
        ans += hashmap[prefix_count] * hashmap[prefix_count - k];
        
        
        return ans;
    }
    
};


// Runtime: 300 ms, faster than 25.00% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 51.2 MB, less than 100.00% of C++ online submissions for Count Number of Nice Subarrays.
// time complexity: O(n)
// space complexity: O(n)