class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> predecessor(n, vector<int> ());
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && isPredecessor(words[i], words[j]))
                    predecessor[i].push_back(j);
            }
        }
        
        vector<int> mem(n, 0);
        int output = 0;
        
        // head of chain
        for (int i = 0; i < n; ++i) {
            output = max(output, 1 + maxPath(predecessor, mem, i));
        }
        
        return output;
    }
    
private:
    bool isPredecessor(const string& w1, const string& w2) {
        int w1_counter = 0, w2_counter = 0;
        // add exactly one letter
        if (w2.length() != w1.length() + 1)
            return false;
        
        int n = w1.length(), m = w2.length();
        int diff = 0;
        
        while (w2_counter < m) {
            if (w1[w1_counter] == w2[w2_counter]) {
                ++w1_counter;
                ++w2_counter;
            }
            else {
                ++w2_counter;
                ++diff;
                if (diff > 1)
                    return false;
            }
        }
        
        return true;
    }
    
    int maxPath(vector<vector<int>>& predecessor, vector<int>& mem, int start) {
        if (mem[start] != 0)
            return mem[start];
        
        int output = 0;
        
        for (int i = 0; i < predecessor[start].size(); ++i) {
            output = max(output, maxPath(predecessor, mem, predecessor[start][i]) + 1);
        }
        
        mem[start] = output;
        return output;
    }
};

// Runtime: 84 ms, faster than 65.61% of C++ online submissions for Longest String Chain.
// Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Longest String Chain.
// time complexity: O(n^2 * m)
// space complexity: O(n^2)