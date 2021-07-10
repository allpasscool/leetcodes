class node{
    node before;
    node next;
    int key;
    int value;
    
    public node(int key, int value)
    {
        this.key = key;
        this.value = value;
        this.before = null;
        this.next = null;
    }
};

class LRUCache {
    node beforeHead;
    node tail;
    int capacity;
    int len;
    HashMap<Integer, node> hashmap;
    
    public LRUCache(int capacity) {
        this.beforeHead = new node(-1, -1);
        this.tail = new node(-2, -2);
        this.beforeHead.next = tail;
        this.tail.before = this.beforeHead;
        this.len = 0;
        this.capacity = capacity;
        this.hashmap = new HashMap<Integer, node>();
    }
    
    public int get(int key) {
        if (hashmap.containsKey(key))
        {
            node n = hashmap.get(key);
            removeNode(key);
            addToHead(n);
            return n.value;
        }
        else
        {
            return -1;
        }
    }
    
    public void put(int key, int value) {
        // System.out.println(key);
        if (hashmap.containsKey(key))
        {
            removeNode(key);
        }
        else if (len == capacity)
        {
            removeTail();
        }
        node n = new node(key, value);
        addToHead(n);
        hashmap.put(key, n);
    }
    
    private void removeTail()
    {
        hashmap.remove(tail.before.key);
        tail.before.before.next = tail;
        tail.before = tail.before.before;
        len--;
    }
    
    private void removeNode(int key)
    {
        // System.out.println("print: " + key);
        node n = hashmap.get(key);
        n.next.before = n.before;
        n.before.next = n.next;
        hashmap.remove(key);
        len--;
    }
    
    private void addToHead(node n)
    {
        hashmap.put(n.key, n);
        n.next = beforeHead.next;
        beforeHead.next = n;
        n.before = beforeHead;
        n.next.before = n;
        len++;
    }
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

 
// Runtime: 55 ms, faster than 19.17% of Java online submissions for LRU Cache.
// Memory Usage: 129.4 MB, less than 5.02% of Java online submissions for LRU Cache.
// time complexity: get and put O(1)
// space complexity: O(n)