class Solution {
public:
    static bool comp(const pair<int, int>& x, const pair<int, int>& y) {
        return (x.second >= y.second);
    }
    
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hash_map;
        int n = nums.size();
        
        if (n == 0) {
            return vector<int> ();
        }
        
        // calculate frequency
        for (int i = 0; i < n; i++) {
            if (hash_map.find(nums[i]) == hash_map.end()) {
                hash_map[nums[i]] = 1;
            }
            else {
                hash_map[nums[i]]++;
            }
        }
        
        //put hash_map into vector
        vector<pair<int, int>> frequency;
        for (auto& i:hash_map) {
            frequency.push_back(i);
        }
        
        // sort frequency;
        sort(frequency.begin(), frequency.end(), comp);
        
        // output
        vector<int> output;
        for (int i = 0; i < k; i++) {
            output.push_back(frequency[i].first);
        }
        
        return output;
    }
};
// Runtime: 24 ms, faster than 35.46% of C++ online submissions for Top K Frequent Elements.
// Memory Usage: 11.4 MB, less than 96.77% of C++ online submissions for Top K Frequent Elements.
// time complexity: O(n log n)
// space complexity: O(n + k)