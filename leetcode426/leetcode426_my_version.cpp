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
        
        inorder(root);
        
        if (arr.size() >= 1) {
            for (int i = 0; i < arr.size() - 1; ++i) {
                arr[i]->right = arr[i + 1];
                arr[i + 1]->left = arr[i];
            }
            
            arr[0]->left = arr[arr.size() - 1];
            arr[arr.size() - 1]->right = arr[0];
        }
        
        return arr[0];
    }
    
private:
    vector<Node*> arr;
    
    void inorder(Node* root) {
        if (!root) 
            return;
        
        if (root->left) {
            inorder(root->left);
        }
        arr.push_back(root);
        if (root->right) {
            inorder(root->right);
        }
    }
};


// Runtime: 8 ms, faster than 63.30% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Convert Binary Search Tree to Sorted Doubly Linked List.
// time complexity: O(n)
// space complexity: O(n)