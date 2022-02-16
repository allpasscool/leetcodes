class LRUCache
{
public:
    LRUCache(int capacity)
    {
        size = 0;
        cap = capacity;
        head = NULL;
        tail = NULL;
    }

    int get(int key)
    {
        if (hashmap.find(key) == hashmap.end())
            return -1;

        int val = hashmap[key]->val;
        remove(hashmap[key]);
        add(key, val);

        return val;
    }

    void put(int key, int value)
    {
        if (hashmap.find(key) != hashmap.end())
        {
            remove(hashmap[key]);
            size--;
        }

        add(key, value);
        size++;

        if (size > cap)
        {
            remove(tail);
            size--;
        }
    }

private:
    struct node
    {
        node *prev, *next;
        int key, val;
    };

    struct node *head, *tail;
    int size, cap;
    unordered_map<int, node *> hashmap;

    void remove(struct node *cur)
    {
        struct node *prev, *next;
        if (cur->prev)
            prev = cur->prev;
        if (cur->next)
            next = cur->next;

        if (prev)
            prev->next = prev->next->next;
        if (next)
            next->prev = next->prev->prev;

        // cur is head
        if (!prev)
            head = cur->next;
        // cur is tail
        if (!next)
            tail = cur->prev;

        hashmap.erase(cur->key);
    }

    void add(int key, int val)
    {
        struct node *newNode = new struct node();
        newNode->key = key;
        newNode->val = val;
        newNode->prev = NULL;
        newNode->next = head;
        hashmap[key] = newNode;

        if (head)
            head->prev = newNode;

        head = newNode;

        if (!tail)
            tail = newNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

// Runtime: 700 ms, faster than 33.50% of C++ online submissions for LRU Cache.
// Memory Usage: 181.4 MB, less than 5.78% of C++ online submissions for LRU Cache.
// time complexity: get O(1), put O(1)
// space complexity: O(capacity)