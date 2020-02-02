class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        hashmap[val].insert(vals.size());
        vals.push_back(val);
        
        if (hashmap[val].size() > 1) {
            return false;
        }
        else {
            return true;
        }
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (hashmap.find(val) == hashmap.end()) {
            return false;
        }
        
        int target_index = *prev(hashmap[val].end());
        int last_elem = vals[vals.size() - 1];
        
        swap(vals[target_index], vals[vals.size() - 1]);
        vals.pop_back();
        hashmap[val].erase(prev(hashmap[val].end()));
        if (hashmap[val].size() == 0) {
            hashmap.erase(val);
        }
        
        // make sure we are not deleting the same and the only elemtn
        if (hashmap.find(last_elem) != hashmap.end()) {
            hashmap[last_elem].erase(prev(hashmap[last_elem].end()));
            hashmap[last_elem].insert(target_index);
        }
        
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return vals[rand() % vals.size()];
    }
    
private:
    vector<int> vals;
    unordered_map<int, set<int>> hashmap; // hashmap[val] = [index1, index2 ...]
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


// Runtime: 60 ms, faster than 71.10% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// Memory Usage: 24.1 MB, less than 25.00% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// time complexity: O(log n)
// space complexity: O(n)