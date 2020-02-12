/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node* treeToDoublyList(Node* root) {
        if (!root)
            return root;
        
        helper(root);
        
        // close DLL
        last->right = first;
        first->left = last;
        return first;
    }
    
private:
    Node* first = nullptr;
    Node* last = nullptr;
    
    void helper(Node* root) {
        if (root) {
            // left
            helper(root->left);
            
            if (last) {
                // link the previous node (last)
                // with the current one (root)
                last->right = root;
                root->left = last;
            }
            else {
                // keep the smallest node
                // to close DLL later on
                first = root;
            }
            
            last = root;
            
            // right
            helper(root->right);
        }
    }
};


// Runtime: 8 ms, faster than 63.30% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
// time complexity: O(n)
// space complexity: O(n)