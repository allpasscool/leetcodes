class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        int n = nums.size();
        
        if (n == 0) {
            return vector<int> ();
        }
        
        // build hash map : character and how often it appears
        for (int i = 0; i < n; i++) {
            if (hash_map.find(nums[i]) == hash_map.end()) {
                hash_map[nums[i]] = 1;
            }
            else {
                hash_map[nums[i]]++;
            }
        }
        
        // init heap the less frequent element first
        // by default is a max heap
        priority_queue<pair<int, int>> pq;
        for (const auto& p: hash_map) {
            pq.emplace(-p.second, p.first);
            // keep size = k
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        
        return ans;
    }
};
// Runtime: 24 ms, faster than 35.46% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.3 MB, less than 96.77% of C++ online submissions for Top K Frequent Elements.
// time complexity: O(n + n log k)  build heap is O(n)
// space complexity: O(n)