class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        unordered_set<string> starts;
        int ans = 0;

        for (auto &s : startWords)
        {
            sort(begin(s), end(s));
            starts.insert(s);
        }

        for (auto &s : targetWords)
        {
            sort(begin(s), end(s));
            for (int i = 0; i < s.size(); i++)
            {
                string subStr = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
                if (starts.find(subStr) != starts.end())
                {
                    ans++;
                    break;
                }
            }
        }

        return ans;
    }
};

// Runtime: 743 ms, faster than 49.38% of C++ online submissions for Count Words Obtained After Adding a Letter.
// Memory Usage: 104.5 MB, less than 77.82% of C++ online submissions for Count Words Obtained After Adding a Letter.
// time complkexity: O(n)
// space complexity: O(n)