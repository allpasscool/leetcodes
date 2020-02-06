class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = upper_bound(begin(hashmap[key]), end(hashmap[key]), 
                             pair<int, string>(timestamp, ""), [](
                             const pair<int, string>& a, const pair<int, string>& b) {
                                 return a.first < b.first;
                             });
        
        return it == hashmap[key].begin() ? "" : prev(it)->second;
    }
    
private:
    unordered_map<string, vector<pair<int, string>>> hashmap;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

// unordered_map<string, vector<pair<int, string>>> m;
// void set(string key, string value, int timestamp) {
//   m[key].push_back({ timestamp, value });
// }
// string get(string key, int timestamp) {
//   auto it = upper_bound(begin(m[key]), end(m[key]), pair<int, string>(timestamp, ""), [](
//     const pair<int, string>& a, const pair<int, string>& b) { return a.first < b.first; });
//   return it == m[key].begin() ? "" : prev(it)->second;
// }


// Runtime: 392 ms, faster than 80.49% of C++ online submissions for Time Based Key-Value Store.
// Memory Usage: 134.3 MB, less than 100.00% of C++ online submissions for Time Based Key-Value Store.
// time complexity: O(log n)
// space complexity: O(n)
// https://leetcode.com/problems/time-based-key-value-store/discuss/226664/C%2B%2B-3-lines-hash-map-%2B-map