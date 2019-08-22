class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        int max_fre = -1;
        
        for (auto& i: nums) {
            hash_map[i]++;
            max_fre = max(max_fre, hash_map[i]);
        }
        
        map<int, vector<int>> buckets;
        for (auto p: hash_map) {
            buckets[p.second].emplace_back(p.first);
        }
        
        vector<int> ans;
        int ans_size = 0;
        for (int i = max_fre; i >= 1; i--) {
            auto it = buckets.find(i);
            if (it == buckets.end()) {
                continue;
            }
            
            for(auto v: it->second) {
                ans.emplace_back(v);
                ans_size++;
                it++;
                if (ans_size == k) {
                    return ans;
                }
            }
        }
        
        return ans;
        
    }
};
// Runtime: 20 ms, faster than 78.89% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.3 MB, less than 96.77% of C++ online submissions for Top K Frequent Elements.
// time complexity: O(n)
// space complexity: O(n)