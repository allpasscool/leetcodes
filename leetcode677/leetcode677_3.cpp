class MapSum {
public:
    /** Initialize your data structure here. */
    MapSum() {
        hashmap;
        root = new TrieNode();
    }
    
    void insert(string key, int val) {
        int delta = val - hashmap[key];
        hashmap[key] = val;
        
        TrieNode* cur = root;
        cur->score += delta;
        
        for (char& c: key) {
            
            if (!cur->children[c]) {
                cur->children[c] = new TrieNode();
            }
            
            cur = cur->children[c];
            cur->score += delta;
        }
    }
    
    int sum(string prefix) {
        TrieNode* cur = root;
        
        for (char& c: prefix) {
            cur = cur->children[c];
            
            if (cur == NULL) {
                return 0;
            }
        }
        
        return cur->score;
    }
private:
    struct TrieNode {
        unordered_map<char, TrieNode*> children;
        int score;
    };
    unordered_map<string, int> hashmap;
    TrieNode* root;
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Map Sum Pairs.
// Memory Usage: 9.9 MB, less than 40.00% of C++ online submissions for Map Sum Pairs.
// time complexity: O(K), K is length of key
// space complexity: O(n), n is the input