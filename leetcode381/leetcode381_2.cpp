class RandomizedCollection {
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool result = hashmap.find(val) == hashmap.end();
        
        hashmap[val].push_back(vals.size());
        vals.push_back({val, hashmap[val].size() - 1});
        
        return result;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        bool result = hashmap.find(val) != hashmap.end();
        
        if (result) {
            pair<int, int> last_pair = vals.back();
            
            // swap last pair and target
            hashmap[last_pair.first][last_pair.second] = hashmap[val].back();
            vals[hashmap[val].back()] = last_pair;
            
            // remove val
            vals.pop_back();
            hashmap[val].pop_back();
            
            // hashmap[val] become empty?
            if (hashmap[val].empty()) {
                hashmap.erase(val);
            }
        }
        
        return result;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        auto r = rand() % vals.size();
        
        return vals[r].first;
    }
    
private:
    unordered_map<int, vector<int>> hashmap; // val, [index]
    vector<pair<int, int>> vals; // {value, index in the hashmap[value]}
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */


// Runtime: 56 ms, faster than 85.41% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// Memory Usage: 23.4 MB, less than 50.00% of C++ online submissions for Insert Delete GetRandom O(1) - Duplicates allowed.
// time complexity: O(1)
// space complexity: O(n)
// https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/discuss/85541/C%2B%2B-128m-Solution-Real-O(1)-Solution