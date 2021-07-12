public class LFUCache {
    // min frequency in cache
    private int min;

    private final int capacity;
    // given key, get value
    private final HashMap<Integer, Integer> keyToVal;
    // given key, get frequency
    private final HashMap<Integer, Integer> keyToCount;
    // given frequency, get keys
    // a LinkedHashSet lets us iterate through the elements in the order in which they were inserted.
    // https://www.geeksforgeeks.org/linkedhashset-in-java-with-examples/
    private final HashMap<Integer, LinkedHashSet<Integer>> countToLRUKeys;
    
    public LFUCache(int capacity) {
        this.min = -1;
        this.capacity = capacity;
        this.keyToVal = new HashMap<>();
        this.keyToCount = new HashMap<>();
        this.countToLRUKeys = new HashMap<>();
    }
    
    // each time get key will update the frequency
    public int get(int key) {
        if (!keyToVal.containsKey(key)) return -1;
        
        int count = keyToCount.get(key);
        countToLRUKeys.get(count).remove(key); // remove key from current count (since we will inc count)
        if (count == min && countToLRUKeys.get(count).size() == 0) min++; // nothing in the current min bucket
        
        putCount(key, count + 1);
        return keyToVal.get(key);
    }
    
    public void put(int key, int value) {
        if (capacity <= 0) return;
        
        if (keyToVal.containsKey(key)) {
            keyToVal.put(key, value); // update key's value
            get(key); // update key's count
            return;
        } 
        
        if (keyToVal.size() >= capacity)
            evict(countToLRUKeys.get(min).iterator().next()); // evict LRU from this min count bucket
        
        min = 1;
        putCount(key, min); // adding new key and count
        keyToVal.put(key, value); // adding new key and value
    }
    
    // remove the key with least frequency
    private void evict(int key) {
        // remove from frequency to key
        countToLRUKeys.get(min).remove(key);
        // remove from key to value
        keyToVal.remove(key);
        // remove from key to frequency
        keyToCount.remove(key);
    }
    
    private void putCount(int key, int count) {
        keyToCount.put(key, count);
        countToLRUKeys.computeIfAbsent(count, ignore -> new LinkedHashSet<>());
        countToLRUKeys.get(count).add(key);
    }
}

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 
// Runtime: 89 ms, faster than 14.35% of Java online submissions for LFU Cache.
// Memory Usage: 122 MB, less than 31.24% of Java online submissions for LFU Cache.
// time complexity: O(1)
// space complexity: O(c)
// https://leetcode.com/problems/lfu-cache/discuss/94521/JAVA-O(1)-very-easy-solution-using-3-HashMaps-and-LinkedHashSet