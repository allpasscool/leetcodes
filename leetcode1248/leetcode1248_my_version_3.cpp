class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        
        // unordered_map<int, int> hashmap;
        vector<int> hashmap(n + 1 + k);
        int prefix_count = 0;
        int ans = 0;
        
        ++hashmap[k];
        for (int i = 0; i < n; ++i) {
            if (nums[i] % 2 == 1) {
                ans += hashmap[prefix_count + k] * hashmap[prefix_count];
                ++prefix_count;
            }
            
            ++hashmap[prefix_count + k];
        }
        
        ans += hashmap[prefix_count + k] * hashmap[prefix_count];
        
        
        return ans;
    }
    
};


// Runtime: 180 ms, faster than 62.50% of C++ online submissions for Count Number of Nice Subarrays.
// Memory Usage: 20.3 MB, less than 100.00% of C++ online submissions for Count Number of Nice Subarrays.
// time complexity: O(n)
// space complexity: O(n + k)