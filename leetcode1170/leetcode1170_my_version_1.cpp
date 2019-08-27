class Solution {
public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> w_fre;
        
        for (auto w: words) {
            w_fre.push_back(calc(w));
        }
        
        // cout << "OK" << endl;
        
        // sort(w_fre.begin(), w_fre.end(), comp);
        sort(w_fre.begin(), w_fre.end());
        
        // cout << "OK" << endl;
        vector<int> ans;
        
        
        
        for (int i = 0; i < queries.size(); i++) {
            int f_q = calc(queries[i]);
            // int j = 0;
            // for (; j < w_fre.size(); j++) {
            //     if (w_fre[j] <= f_q) {
            //         ans.push_back(j);
            //         break;
            //     }
            // }
            // if (j == w_fre.size()) {
            //     ans.push_back(w_fre.size());
            // }
            int j = w_fre.size() - 1;
            for (; j >= 0; j--) {
                if (w_fre[j] <= f_q) {
                    ans.push_back(w_fre.size() - j - 1);
                    break;
                }
            }
            if (j == -1) {
                ans.push_back(w_fre.size());
            }
        }
        
        return ans;
        
    }
private:
    // static bool comp(int n1, int n2) {
    //     return n1 < n2;
    // }
    
    int calc(string s) {
        int fre[26] = {0};
        
        for (auto c: s) {
            fre[c - 'a']++;
        }
        
        for (int i = 0; i < 26; i++) {
            if (fre[i] > 0) {
                return fre[i];
            }
        }
        
        return 0;
    }
};
// Runtime: 24 ms, faster than 71.20% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// Memory Usage: 10.9 MB, less than 100.00% of C++ online submissions for Compare Strings by Frequency of the Smallest Character.
// time complexity: O(n * n1 * m + m * m1) n is queries, n1 is each query, m is words, m1 is each word
// space complexity: O(m)