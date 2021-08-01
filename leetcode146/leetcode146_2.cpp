
// Runtime: 440 ms, faster than 33.96% of C++ online submissions for LRU Cache.
// Memory Usage: 175.9 MB, less than 17.07% of C++ online submissions for LRU Cache.
// time complexity: O(1) both put and get
// space complexity: O(cap)
// https://leetcode.com/problems/lru-cache/discuss/45976/C%2B%2B11-code-74ms-Hash-table-%2B-List
class LRUCache
{
public:
    LRUCache(int capacity)
    {
        this->size = capacity;
    }

    int get(int key)
    {
        if (keyToIter.find(key) == keyToIter.end())
            return -1;
        updateLRU(key);
        return keyToValue[key];
    }

    void put(int key, int value)
    {
        if (lru.size() == size && keyToValue.find(key) == keyToValue.end())
            evict();
        updateLRU(key);
        keyToValue[key] = value;
    }

private:
    int size;
    list<int> lru;
    unordered_map<int, list<int>::iterator> keyToIter;
    unordered_map<int, int> keyToValue;

    void updateLRU(int key)
    {
        if (keyToValue.find(key) != keyToValue.end())
            lru.erase(keyToIter[key]);
        lru.push_front(key);
        keyToIter[key] = lru.begin();
    }

    void evict()
    {
        keyToIter.erase(lru.back());
        keyToValue.erase(lru.back());
        lru.pop_back();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// int size;
// list<int> lru;                              // MRU ... LRU
// unordered_map<int, list<int>::iterator> mp; // key -> iterator
// unordered_map<int, int> kv;                 // key -> value

// LRUCache(int capacity) : size(capacity) {}
// int get(int key) {
//     if (kv.count(key) == 0) return -1;
//     updateLRU(key);
//     return kv[key];
// }
// void put(int key, int value) {
//     if (kv.size() == size && kv.count(key) == 0)
//         evict();
//     updateLRU(key);
//     kv[key] = value;
// }
// void updateLRU(int key) {
//     if (kv.count(key))
//         lru.erase(mp[key]);
//     lru.push_front(key);
//     mp[key] = lru.begin();
// }
// void evict() {
//     mp.erase(lru.back());
//     kv.erase(lru.back());
//     lru.pop_back();
// }