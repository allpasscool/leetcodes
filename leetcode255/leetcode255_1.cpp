class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int n = preorder.size();
        vector<int> inorder; // in BST, in order will be in increasing order
        
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            if (st.empty() || preorder[i] < st.top()) {
                st.push(preorder[i]);
            }
            else if (preorder[i] > st.top()) {
                while (!st.empty() && st.top() < preorder[i]) {
                    int top = st.top();
                    st.pop();
                    // in order should be increasing order
                    // if top is smaller than last element in inorder, then wrong
                    if (inorder.size() > 0 && top < inorder[inorder.size() - 1]) {
                        return false;
                    }
                    
                    inorder.push_back(top);
                }
                
                st.push(preorder[i]);
            }
        }
        
        while (!st.empty()) {
            int top = st.top();
            st.pop();
            inorder.push_back(top);
        }
        
        for (int i = 1; i < inorder.size(); i++) {
            if (inorder[i] < inorder[i - 1]) {
                return false;
            }
        }
        
        return true;
    }
};

// Runtime: 44 ms, faster than 63.64% of C++ online submissions for Verify Preorder Sequence in Binary Search Tree.
// Memory Usage: 12.6 MB, less than 33.33% of C++ online submissions for Verify Preorder Sequence in Binary Search Tree.
// time complexity: O(n)
// space complexity: O(n)