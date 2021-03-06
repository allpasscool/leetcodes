class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord))
            return 0;
        
        int len = beginWord.length();
        
        unordered_set<string> q1{beginWord};
        unordered_set<string> q2{endWord};
        
        int step = 0;
        
        while (!q1.empty() && !q2.empty()) {
            ++step;
            
            // Always expend the smaller queue first
            if (q1.size() > q2.size())
                std::swap(q1, q2);
            
            
            unordered_set<string> q;
            
            for (string w : q1) {
                for (int i = 0;i < len; ++i) {
                    char ch = w[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        w[i] = j;
                        if (q2.count(w))
                            return step + 1;
                        
                        if (!dict.count(w))
                            continue;
                        
                        dict.erase(w);
                        q.insert(w);
                    }
                    w[i] = ch;
                }
            }
            
            std::swap(q, q1);
        }
        
        return 0;
    }
};


// Runtime: 40 ms, faster than 92.71% of C++ online submissions for Word Ladder.
// Memory Usage: 10.2 MB, less than 100.00% of C++ online submissions for Word Ladder.
// time complexity: O(n * 26 ^ length), length = len(word)
// space complexity: O(n)

// http://zxi.mytechroad.com/blog/searching/127-word-ladder/
// // Author: Huahua
// // Running time: 32 ms (better than 96.6%)
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());        
//         if (!dict.count(endWord)) return 0;
        
//         int l = beginWord.length();
        
//         unordered_set<string> q1{beginWord};
//         unordered_set<string> q2{endWord};
                
//         int step = 0;
        
//         while (!q1.empty() && !q2.empty()) {
//             ++step;
            
//             // Always expend the smaller queue first
//             if (q1.size() > q2.size())
//                 std::swap(q1, q2);
                        
//             unordered_set<string> q;
            
//             for (string w : q1) {
//                 for (int i = 0; i < l; i++) {
//                     char ch = w[i];
//                     for (int j = 'a'; j <= 'z'; j++) {
//                         w[i] = j;
//                         if (q2.count(w)) return step + 1;
//                         if (!dict.count(w)) continue;                        
//                         dict.erase(w);
//                         q.insert(w);
//                     }
//                     w[i] = ch;
//                 }
//             }
            
//             std::swap(q, q1);
//         }
        
//         return 0;
//     }
// };