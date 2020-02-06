class TimeMap {
public:
    /** Initialize your data structure here. */
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        hashmap[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        string ans = "";
        
        auto& arr = hashmap[key];
        
        int start = 0, end = arr.size();
        
        while (start < end) {
            int mid = start + (end - start) / 2;
            
            if (arr[mid].first < timestamp) {
                ans = arr[mid].second;
                start = mid + 1;
            }
            else if (arr[mid].first > timestamp) {
                end = mid;
            }
            else {
                return arr[mid].second;
            }
        }
        
        return ans;
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


// Runtime: 388 ms, faster than 84.90% of C++ online submissions for Time Based Key-Value Store.
// Memory Usage: 134.7 MB, less than 100.00% of C++ online submissions for Time Based Key-Value Store.
// time complexity: O(1) set, O(log n) get
// space complexity: O(1)