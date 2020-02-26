class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        for (auto word : words) {
            ++freq[word];
        }
        
        vector<pair<int, string>> ans(freq.size());
        int i = 0;
        for (auto word_fre : freq) {
            ans[i] = {word_fre.second, word_fre.first};
            ++i;
        }
        
        sort(begin(ans), end(ans), comp);
        
        vector<string> output(k);
        
        for (i = 0; i < k; ++i) {
            output[i] = ans[i].second;
        }
        
        return output;
    }
    
private:
    static bool comp(pair<int, string>& p1, pair<int, string>& p2) {
        return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
    }
};

// Runtime: 12 ms, faster than 97.17% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 11.2 MB, less than 100.00% of C++ online submissions for Top K Frequent Words.
// time complexity: O(n log n)
// space complexity: O(n)