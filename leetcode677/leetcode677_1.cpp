class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        hashmap[key] = val;
    }
    
    int sum(string prefix) {
        int ans = 0;
        int n = prefix.size();
        
        for (auto& p: hashmap) {
            string s = p.first;
            
            if (s.length() < n) {
                continue;
            }
            
            string subs = s.substr(0, n);
            
            if (subs == prefix) {
                ans += p.second;
            }
        }
        
        return ans;
    }
private:
    unordered_map<string, int> hashmap;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// Runtime: 4 ms, faster than 76.38% of C++ online submissions for Map Sum Pairs.
// Memory Usage: 9.4 MB, less than 100.00% of C++ online submissions for Map Sum Pairs.
// time complexity: insertion O(1) sum operation O(N * P), N is the number of item in hashmap and P is the length of prefix
// space complexity: O(n) size of insertion key and value