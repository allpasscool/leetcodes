class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int q_n = queries.size(), w_n = words.size();
        vector<int> q_f;
        vector<int> w_f;
        
        for (int i = 0; i < q_n; i++) {
            q_f.push_back(calFre(queries[i]));
        }
        
        for (int i = 0; i < w_n; i++) {
            w_f.push_back(calFre(words[i]));
        }
        
        vector<int> output;
        
        for (int i = 0; i < q_n; i++) {
            int count = 0;
            for (int j = 0; j < w_n; j++) {
                if (q_f[i] < w_f[j]) {
                    count++;
                }
            }
            output.push_back(count);
        }
        
        return output;
    }
    
    int calFre(string& s) {
        int n = s.length();
        char small = 'z';
        int count = 0;
        
        for (int i = 0; i < n; i++) {
            if (s[i] < small) {
                small = s[i];
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (s[i] == small) {
                count++;
            }
        }
        
        return count;
    }
};
// Runtime: 68 ms, faster than 18.40% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// Memory Usage: 11.1 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// time complexity: O(n * m + n * n1 + m * m1) n is query and n1 is each query, m is words, m1 is each word
// space complexity: O(n + m)