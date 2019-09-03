class LRUCache {
private:
    struct DLinkedNode {
        int key;
        int value;
        DLinkedNode* prev;
        DLinkedNode* next;
    };
    
    void addNode (DLinkedNode* node) {
        /**
         * Always add the new node right after head.
         */
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }
    
    void removeNode(DLinkedNode* node) {
        /**
         * Remove an existing node from the linked list.
         */
        
        DLinkedNode* prev = node->prev;
        DLinkedNode* next = node->next;
        
        prev->next = next;
        next->prev = prev;
    }
    
    void moveToHead(DLinkedNode* node) {
        /**
         * Move certain node in between to the head;
         */
        removeNode(node);
        addNode(node);
    }
    
    DLinkedNode* popTail() {
        /**
        * Pop the current tail.
        */
        DLinkedNode* res = tail->prev;
        removeNode(res);
        return res;
    }
    
    unordered_map<int, DLinkedNode*> cache;
    int size;
    int cap;
    DLinkedNode* head, * tail;
    
public:
    LRUCache(int capacity) {
        this->size = 0;
        this->cap = capacity;
        
        head = new DLinkedNode();
        // head->prev = null;
        
        tail = new DLinkedNode();
        
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // cout << "get: " << key << endl;
        DLinkedNode* node = cache[key];
        if (node == NULL) {
            return -1;
        }
        
        // move the accessed node to the head
        moveToHead(node);
        
        return node->value;
    }
    
    void put(int key, int value) {
        // cout << "put: " << key << ", " << value << endl;
        DLinkedNode* node = cache[key];
        
        if (node == NULL) {
            DLinkedNode* new_node = new DLinkedNode();
            new_node->key = key;
            new_node->value = value;
            
            cache[key] = new_node;
            addNode(new_node);
            
            size++;
            
            if(size > cap) {
                // pop the tail
                DLinkedNode* poped_node = popTail();
                cache.erase(poped_node->key);
                size--;
            }
        }
        else {
            // updat the value
            node->value = value;
            moveToHead(node);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// Runtime: 108 ms, faster than 79.78% of C++ online submissions for LRU Cache.
// Memory Usage: 38 MB, less than 79.27% of C++ online submissions for LRU Cache.
// time complexity: O(1) both put and get
// space complexity: O(cap)