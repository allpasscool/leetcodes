class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashmap.find(val) != hashmap.end()) {
            return false;
        }
        
        hashmap[val] = vals.size();
        vals.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            return false;
        }
        
        int last_elem = vals.back();
        int target_index = hashmap[val];
        
        // swap target_index and last index
        swap(vals[vals.size() - 1], vals[target_index]);
        hashmap[last_elem] = target_index;
        
        // erase
        hashmap.erase(val);
        vals.pop_back();
        
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % vals.size();
        
        return vals[r];
    }
    
private:
    unordered_map<int, int> hashmap; // hashmap[value] = index
    vector<int> vals; // values
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

// Runtime: 48 ms, faster than 94.88% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 22.3 MB, less than 76.92% of C++ online submissions for Insert Delete GetRandom O(1).
// time complexity: O(1)
// space complexity: O(1)