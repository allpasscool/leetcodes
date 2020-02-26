class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        
        for (auto word : words) {
            ++freq[word];
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        
        for (auto p : freq) {
            pq.push({p.second, p.first});
            
            if (pq.size() > k) {
                pq.pop();
            }
        }
        
        vector<string> output(k);
        
        for (int i = k - 1; i >= 0; i--) {
            output[i] = pq.top().second;
            pq.pop();
        }
        
        return output;
    }
    
private:
    struct comp {
        bool operator() (const pair<int, string>& p1, const pair<int, string>& p2) {
            return p1.first > p2.first || (p1.first == p2.first && p1.second < p2.second);
        }
    };
};


// Runtime: 12 ms, faster than 97.14% of C++ online submissions for Top K Frequent Words.
// Memory Usage: 11.5 MB, less than 83.33% of C++ online submissions for Top K Frequent Words.
// time complexity: O(n)
// space complexity: O(n log k)