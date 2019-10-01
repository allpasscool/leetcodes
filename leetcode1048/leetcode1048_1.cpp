class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        unordered_map<string, int> dp;
        int output = 0;
        
        for (string& w: words) {
            int best = 0;
            // construct a word with missing one letter
            for (int i = 0; i < w.length(); ++i) {
                // w.substr(i + 1) means from i + 1 to the end
                string word = w.substr(0, i) + w.substr(i + 1);
                best = max(best, dp[word] + 1);
            }
            dp[w] = best;
            output = max(output, best);
        }
        
        return output;
    }
    
private:
    static bool comp(const string& w1, const string& w2) {
        return w1.length() < w2.length();
    }
};

// Runtime: 124 ms, faster than 45.43% of C++ online submissions for Longest String Chain.
// Memory Usage: 49.6 MB, less than 100.00% of C++ online submissions for Longest String Chain.
// time complexity: O(n * m + n log n) n is # of words, m is the longest lenth of word
// space complexity: O(n)