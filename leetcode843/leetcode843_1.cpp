/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution
{
public:
    void findSecretWord(vector<string> &wordlist, Master &master)
    {
        for (int i = 0, x = 0; i < 10 && x < 6; ++i)
        {
            unordered_map<string, int> count;
            for (string w1 : wordlist)
                for (string w2 : wordlist)
                    if (match(w1, w2) == 0)
                        count[w1]++;
            pair<string, int> minimax = {wordlist[0], 1000};
            for (string w : wordlist)
                if (count[w] <= minimax.second)
                    minimax = make_pair(w, count[w]);
            x = master.guess(minimax.first);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(minimax.first, w) == x)
                    wordlist2.push_back(w);
            wordlist = wordlist2;
        }
    }

    int match(string &w1, string &w2)
    {
        int count = 0;

        for (int i = 0; i < w1.size(); i++)
        {
            if (w1[i] == w2[i])
                count++;
        }

        return count;
    }
};

// Runtime: 4 ms, faster than 48.10% of C++ online submissions for Guess the Word.
// Memory Usage: 6.7 MB, less than 16.52% of C++ online submissions for Guess the Word.
// time complexity: O(n^2)
// space complexity: O(n)
// https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison