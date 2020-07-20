struct CacheNode {
    int key;
    int value;
    int freq;
    long tick;
    
    // Defines the order, smaller one will be evicted first
    bool operator <(const CacheNode& rhs) const {
        if (freq < rhs.freq)
            return true;
        if (freq == rhs.freq)
            return tick < rhs.tick;
        return false;
    }
};

class LFUCache {
public:
    LFUCache(int capacity):capacity_(capacity), tick_(0) {
        
    }
    
    int get(int key) {
        auto it = hashmap.find(key);
        if (it == hashmap.cend())
            return -1;
        int value = it->second.value;
        // update tick and freq
        touch(it->second);
        return value;
    }
    
    void put(int key, int value) {
        if (capacity_ == 0)
            return;
        
        auto it = hashmap.find(key);
        
        // already exists
        if (it != hashmap.cend()) {
            // key exists, update value and touch
            it->second.value = value;;
            touch(it->second);
            return;
        }
        
        // reach capacity
        if (hashmap.size() == capacity_) {
            // remove the first node in cache
            const CacheNode& node = *cache_.cbegin();
            hashmap.erase(node.key);
            cache_.erase(node);
        }
        
        // adding new node
        CacheNode node{key, value, 1, ++tick_};
        hashmap[node.key] = node;
        cache_.insert(node);
    }
private:
    void touch(CacheNode& node) {
        cache_.erase(node); // log(capacity)
        ++node.freq;
        node.tick = ++tick_;
        cache_.insert(node); // log(capacity)
    }
    
    long tick_;
    int capacity_;
    unordered_map<int, CacheNode> hashmap;
    set<CacheNode> cache_;
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Runtime: 212 ms, faster than 65.24% of C++ online submissions for LFU Cache.
// Memory Usage: 44.9 MB, less than 15.85% of C++ online submissions for LFU Cache.
// time complexity: O(log c)
// space complexity: O(c)

// http://zxi.mytechroad.com/blog/hashtable/leetcode-460-lfu-cache/
// // Author: Huahua
// // Running time: 99 ms
// struct CacheNode {
//     int key;
//     int value;
//     int freq;
//     long tick;
    
//     // Defines the order, smaller one will be evicted first
//     bool operator <(const CacheNode& rhs) const {
//         if (freq < rhs.freq) return true;
//         if (freq == rhs.freq) return tick < rhs.tick;
//         return false;
//     }
// };
// class LFUCache {
// public:
//     LFUCache(int capacity):capacity_(capacity), tick_(0) {}
    
//     int get(int key) {
//         auto it = m_.find(key);
//         if (it == m_.cend()) return -1;
//         int value = it->second.value;
//         touch(it->second);
//         return value;
//     }
    
//     void put(int key, int value) {
//         if (capacity_ == 0) return;
        
//         auto it = m_.find(key);
        
//         if (it != m_.cend()) {
//             // Key exists, update value and touch
//             it->second.value = value;            
//             touch(it->second);            
//             return;
//         }
        
//         if (m_.size() == capacity_) {
//             // Remove the first node in cache
//             const CacheNode& node = *cache_.cbegin();
//             m_.erase(node.key);
//             cache_.erase(node);
//         }
        
//         CacheNode node{key, value, 1, ++tick_};
//         m_[node.key] = node;
//         cache_.insert(node);
//     }
// private:
//     void touch(CacheNode& node) {
//         cache_.erase(node);     // log(capacity)        
//         ++node.freq;
//         node.tick = ++tick_;
//         cache_.insert(node);    // log(capacity)
//     }
    
//     long tick_;
//     int capacity_;
//     unordered_map<int, CacheNode> m_;
//     set<CacheNode> cache_;
    
// };