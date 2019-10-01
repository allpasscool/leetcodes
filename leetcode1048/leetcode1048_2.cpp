class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<vector<bool>> predecessor(n, vector<bool> (n, false));
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                predecessor[i][j] = isPredecessor(words[i], words[j]);
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
    
    int maxPath(vector<vector<bool>>& predecessor, vector<int>& mem, int start) {
        if (mem[start] != 0)
            return mem[start];
        
        int output = 0;
        
        for (int i = 0; i < mem.size(); ++i) {
            if (i != start && predecessor[start][i]) {
                output = max(output, maxPath(predecessor, mem, i) + 1);
            }
        }
        
        mem[start] = output;
        return output;
    }
};

// Runtime: 384 ms, faster than 12.25% of C++ online submissions for Longest String Chain.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Longest String Chain.
// time complexity: O(n^2 * m) n is # of words, m is the longest length of word
// space complexity: O(n^2)