class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        int delta = val - hashmap[key];
        hashmap[key] = val;
        
        string prefix = "";
        
        for (char c: key) {
            prefix += c;
            score[prefix] += delta;
        }
    }
    
    int sum(string prefix) {
        return score[prefix];
    }
private:
    unordered_map<string, int> hashmap;
    unordered_map<string, int> score;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// Runtime: 4 ms, faster than 76.38% of C++ online submissions for Map Sum Pairs.
// Memory Usage: 9.8 MB, less than 40.00% of C++ online submissions for Map Sum Pairs.
// time complexity: insertion O(K), K is the length of key, sum O(1)
// space complexity: O(N), N is input key and value