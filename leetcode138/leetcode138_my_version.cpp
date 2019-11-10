/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans_head;
        if (head == NULL)
            return ans_head;
        
        unordered_map<Node*, Node*> hashmap; // sotre address to address
        Node* cur = head;
        ans_head = new Node(head->val, nullptr, nullptr);
        Node* cur_copy = ans_head;
        hashmap[head] = ans_head;
        cur = cur->next;
        
        // build the copy list and their value
        while (cur != nullptr) {
            Node* tmp = new Node(cur->val, nullptr, nullptr);
            cur_copy->next = tmp;
            cur_copy = cur_copy->next;
            
            hashmap[cur] = tmp;
            cur = cur->next;
        }
        
        // assign _random to our copy list
        cur = head;
        cur_copy = ans_head;
        while (cur != nullptr) {
            cur_copy->random = hashmap[cur->random];
            cur = cur->next;
            cur_copy = cur_copy->next;
        }
        
        return ans_head;
    }
};


// Runtime: 32 ms, faster than 74.11% of C++ online submissions for Copy List with Random Pointer.
// Memory Usage: 22.1 MB, less than 95.24% of C++ online submissions for Copy List with Random Pointer.
// time complexity: O(n)
// space complexity: O(n)