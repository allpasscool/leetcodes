/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) {
            return head;
        }
        
        stack<Node*> st;
        Node* pre = nullptr;
        
        st.push(head);
        
        while (!st.empty()) {
            auto cur = st.top();
            st.pop();
            
            if (pre) {
                pre->next = cur;
            }
            cur->prev = pre;
            
            if (cur->next) {
                st.push(cur->next);
            }
            
            if (cur->child) {
                st.push(cur->child);
            }
            cur->child = nullptr;
            
            pre = cur;
        }
        
        return head;
    }
};


// Runtime: 4 ms, faster than 89.53% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// Memory Usage: 9.8 MB, less than 100.00% of C++ online submissions for Flatten a Multilevel Doubly Linked List.
// time complexity: O(n)
// space complexity: O(n)