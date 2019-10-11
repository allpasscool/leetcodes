class LogSystem {
private:
    multimap<string, int> m;
    
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        m.emplace(timestamp, id);
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        if (gra == "Year") {
            s = s.substr(0, 4) + ":01:01:00:00:00";
            e = e.substr(0, 4) + ":12:31:23:59:59";
        }
        else if (gra == "Month") {
            s = s.substr(0, 7) + ":01:00:00:00";
            e = e.substr(0, 7) + ":31:23:59:59";
        }
        else if (gra == "Day") {
            s = s.substr(0, 10) + ":00:00:00";
            e = e.substr(0, 10) + ":23:59:59";
        }
        else if (gra == "Hour") {
            s = s.substr(0, 13) + ":00:00";
            e = e.substr(0, 13) + ":59:59";
        }
        else if (gra == "Minute") {
            s = s.substr(0, 16) + ":00";
            e = e.substr(0, 16) + ":59";
        }
        auto start = m.lower_bound(s), end = m.upper_bound(e);
        vector<int> ans;
        for (auto iter = start; iter != end; ++iter)
            ans.push_back(iter->second);
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem* obj = new LogSystem();
 * obj->put(id,timestamp);
 * vector<int> param_2 = obj->retrieve(s,e,gra);
 */


// Runtime: 20 ms, faster than 98.35% of C++ online submissions for Design Log Storage System.
// Memory Usage: 14 MB, less than 100.00% of C++ online submissions for Design Log Storage System.
// time complexity: put: O(log(n) + Rebalance ) retrieve: O(log n)
// space complexity: O(n)
// https://leetcode.com/problems/design-log-storage-system/discuss/105025/Straight-forward-C%2B%2B-multimap-solution