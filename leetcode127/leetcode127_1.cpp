class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        // no end word
        if (!dict.count(endWord))
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        
        int length = beginWord.length();
        int step = 0;
        
        while (!q.empty()) {
            ++step;
            for (int size = q.size(); size > 0; size--) {
                string word = q.front();
                q.pop();
                for (int i = 0; i < length; ++i) {
                    char ch = word[i];
                    for (char j = 'a'; j <= 'z'; ++j) {
                        word[i] = j;
                        // Found this solution
                        if (word == endWord)
                            return step + 1;
                        // Not in dict, skip it
                        if (!dict.count(word))
                            continue;
                        // Remove new word from dict
                        dict.erase(word);
                        // Add new word into queue
                        q.push(word);
                    }
                    word[i] = ch;
                }
            }
        }
        
        return 0;
    }
};


// Runtime: 136 ms, faster than 60.52% of C++ online submissions for Word Ladder.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Word Ladder.
// time complexity: O(n * 26 ^ length), length = len(word)
// space complexity: O(n)

// http://zxi.mytechroad.com/blog/searching/127-word-ladder/
// // Author: Huahua
// // Running time: 93 ms
// class Solution {
// public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         unordered_set<string> dict(wordList.begin(), wordList.end());        
//         if (!dict.count(endWord)) return 0;
        
//         queue<string> q;
//         q.push(beginWord);
        
//         int l = beginWord.length();
//         int step = 0;
        
//         while (!q.empty()) {
//             ++step;
//             for (int size = q.size(); size > 0; size--) {                
//                 string w = q.front();                
//                 q.pop();
//                 for (int i = 0; i < l; i++) {                
//                     char ch = w[i];
//                     for (int j = 'a'; j <= 'z'; j++) {
//                         w[i] = j;
//                         // Found the solution
//                         if (w == endWord) return step + 1;
//                         // Not in dict, skip it
//                         if (!dict.count(w)) continue;
//                         // Remove new word from dict
//                         dict.erase(w);
//                         // Add new word into queue
//                         q.push(w);                    
//                     }
//                     w[i] = ch;
//                 }
//             }
//         }
//         return 0;
//     }
// };