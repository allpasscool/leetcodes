/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        int num_of_null = 0;
        string ans;
        
        // cout << "serialize" << endl;
        // cout << "OK" << endl << !root << endl;
        
        if (!root) {
            // cout << "root is empty" << endl;
            return "[]";
        }
        
        // cout << "!!" << endl;
        
        q.push(root);
        
        ans += '[';
        
        while (q.size() != num_of_null) {
            int n = q.size();
            num_of_null = 0;
            
            for (int i = 0; i < n; ++i) {
                auto tmp = q.front();
                q.pop();
                
                if (tmp) {
                    ans += to_string(tmp->val) + ",";
                    
                    if (tmp->left) {
                        q.push(tmp->left);
                    }
                    else {
                        q.push(NULL);
                        ++num_of_null;
                    }
                    
                    if (tmp->right) {
                        q.push(tmp->right);
                    }
                    else {
                        q.push(NULL);
                        ++num_of_null;
                    }
                }
                else {
                    ans += "null,";
                    
                    q.push(NULL);
                    q.push(NULL);
                    
                    num_of_null += 2;
                }
                
            }
        }
        
        if (ans.length() > 1)
            ans[ans.length() - 1] = ']';
        else
            ans += ']';
        
        // cout << "finish serialize" << endl << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        // cout << data << endl;
        
        TreeNode* root = nullptr;
        queue<string> q;
        
        // cout << data << endl;
        if (data == "[]") {
            // cout << "data is []" << endl;
            return root;
        }
        
        // cout << "??";
        stringstream sstream(data.substr(1, data.length() - 2));
        string tmp;
        
        while (getline(sstream, tmp, ',')) {
            q.push(tmp);
            // cout << tmp << endl;
        }
        
        
        if (q.front() == "null" || q.empty()) {
            return root;
        }
        else {
            // cout << "enter";
            root = new TreeNode(stoi(q.front()));
            // cout << q.front() << endl;
            q.pop();
        }
        
        queue<TreeNode*> bfs;
        bfs.push(root);
        
        // test what is in q
        // while (!q.empty()) {
        //     cout << q.front() << endl;
        //     q.pop();
        // }
        
        // assign all data in q into tree
        while (!q.empty()) {
            // cout << q.size() << endl;
            TreeNode* cur = bfs.front();
            bfs.pop();
            
            // current is null
            // its left and right child is 
            if (!cur) {
                // cout << "current is empty" << endl;
                bfs.push(nullptr);
                bfs.push(nullptr);
                q.pop();
                q.pop();
                continue;
            }
            
            
            // cout << "left child: " << q.front();
            // left child
            string left = q.front();
            // cout << ": " << left << endl;
            q.pop();
            if (left == "null") {
                bfs.push(nullptr);
            }
            else {
                TreeNode* left_child = new TreeNode(stoi(left));
                cur->left = left_child;
                bfs.push(left_child);
            }
            
            // cout << "right child: " << q.front() << endl;
            // right child
            string right = q.front();
            q.pop();
            if (right == "null") {
                bfs.push(nullptr);
            }
            else {
                TreeNode* right_child = new TreeNode(stoi(right));
                cur->right = right_child;
                bfs.push(right_child);
            }
        }
        
        // cout << "finish deserialize" << endl;
        
        return root;
    }
};

// time limited exceed

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));