class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        auto get_mask = [](string &w)
        {
            return accumulate(begin(w), end(w), 0, [](int mask, char ch)
                              { return mask + (1 << (ch - 'a')); });
        };
        unordered_set<int> s;
        for (auto &w : startWords)
            s.insert(get_mask(w));
        int res = 0;
        for (auto &w : targetWords)
        {
            int mask = get_mask(w);
            res += any_of(begin(w), end(w), [&](char ch)
                          { return s.count(mask - (1 << (ch - 'a'))); });
        }
        return res;
    }
};

// https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/submissions/
// Runtime: 228 ms, faster than 99.89% of C++ online submissions for Count Words Obtained After Adding a Letter.
// Memory Usage: 98.7 MB, less than 93.49% of C++ online submissions for Count Words Obtained After Adding a Letter.
// time complexity: O(n)
// space complexity: O(n)