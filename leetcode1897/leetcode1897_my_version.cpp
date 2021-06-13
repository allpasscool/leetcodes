class Solution
{
public:
    bool makeEqual(vector<string> &words)
    {
        int alpha[26] = {0};

        for (string w : words)
        {
            for (char c : w)
            {
                alpha[c - 'a']++;
            }
        }

        int n = words.size();

        for (int i = 0; i < 26; i++)
        {
            if (alpha[i] % n != 0)
            {
                return false;
            }
        }

        return true;
    }
};

// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
// Memory Usage: 12.1 MB, less than 33.33% of C++ online submissions for Redistribute Characters to Make All Strings Equal.
// time complexity: O(n)
// space complexity: O(1)