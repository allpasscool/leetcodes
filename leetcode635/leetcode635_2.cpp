class LogSystem {
private:
    multimap<string, int> log;
    string low = "2000:00:00:00:00:00";
    string high = "2017:12:31:23:59:59";
    unordered_map<string, int> map = {{"Year", 4}, {"Month", 7}, {"Day", 10},
                                      {"Hour", 13}, {"Minute", 16}, {"Second", 19}};

public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        log.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        int len = map[gra];
        s = s.substr(0, len) + low.substr(len);
        e = e.substr(0, len) + high.substr(len);
        auto first = log.lower_bound(s);
        auto last = log.upper_bound(e);
        vector<int> result;
        for (auto it = first; it != last; it++)
            result.push_back(it->second);
        return result;
    }
};

// Runtime: 28 ms, faster than 66.51% of C++ online submissions for Design Log Storage System.
// Memory Usage: 14.1 MB, less than 100.00% of C++ online submissions for Design Log Storage System.
// time complexity: put: O(log(n) + Rebalance ) retrieve: O(log n)
// space complexity: O(n)
// https://leetcode.com/problems/design-log-storage-system/discuss/105025/Straight-forward-C%2B%2B-multimap-solution