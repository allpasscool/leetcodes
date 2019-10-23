class Solution {
public:
    bool canCross(vector<int>& stones) {
        unordered_map<int, set<int>> map;
        unordered_set<int> stones_loc;
        int n = stones.size();
        
        
        for (int i = 0; i < n; ++i) {
            stones_loc.insert(stones[i]);
        }
        
        map[0].insert(0);
        
        for (int i = 0; i < n; ++i) {
            for (int k : map[stones[i]]) {
                for (int step = k - 1; step <= k + 1; ++step) {
                    if (step > 0 && stones_loc.find(stones[i] + step) != stones_loc.end()) {
                        map[stones[i] + step].insert(step);
                    }
                }
            }
        }
        
        return map[stones[n - 1]].size() > 0;
    }
};

// Runtime: 180 ms, faster than 36.56% of C++ online submissions for Frog Jump.
// Memory Usage: 38.3 MB, less than 15.00% of C++ online submissions for Frog Jump.
// time complexity: O(n^2)
// space complexity: O(n^2)