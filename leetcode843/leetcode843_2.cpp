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
        int count[6][26] = {0};
        int x = 0, best;
        for (int t = 0; t < 10 && x < 6; ++t)
        {
            // memset(count, 0, 156 * sizeof(int));
            for (string w : wordlist)
                for (int i = 0; i < 6; ++i)
                    count[i][w[i] - 'a']++;
            best = 0;
            string guess = wordlist[0];
            for (string w : wordlist)
            {
                int score = 0;
                for (int i = 0; i < 6; ++i)
                    score += count[i][w[i] - 'a'];
                if (score > best)
                {
                    guess = w;
                    best = score;
                }
            }
            x = master.guess(guess);
            vector<string> wordlist2;
            for (string w : wordlist)
                if (match(guess, w) == x)
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

// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Guess the Word.
// Memory Usage: 6.4 MB, less than 68.10% of C++ online submissions for Guess the Word.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/guess-the-word/discuss/133862/Random-Guess-and-Minimax-Guess-with-Comparison