class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (hashset.find(val) != hashset.end()) {
            return false;
        }
        
        hashset.insert(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (hashset.find(val) != hashset.end()) {
            hashset.erase(val);
            return true;
        }
        
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int ran = (rand() % hashset.size());
        
        int ans;
        
        auto tmp = hashset.begin();
        advance(tmp, ran);
        
        return *tmp;
    }
    
private:
    unordered_set<int> hashset;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


// Runtime: 92 ms, faster than 14.06% of C++ online submissions for Insert Delete GetRandom O(1).
// Memory Usage: 22 MB, less than 100.00% of C++ online submissions for Insert Delete GetRandom O(1).
// time complexity: O(1)
// space complexity: O(1)