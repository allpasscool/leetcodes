class Solution
{
public:
    vector<string> reorderLogFiles(vector<string> &logs)
    {
        vector<string> dig;
        vector<pair<string, string>> let;
        vector<string> ans(logs.size());

        for (string &log : logs)
        {
            if (isDigitLog(log))
                dig.push_back(log);
            else
            {
                int i = 0;
                for (; i < log.size(); i++)
                {
                    if (log[i] == ' ')
                        break;
                }

                let.push_back({log.substr(0, i + 1), log.substr(i + 1, log.size() - i - 1)});
            }
        }

        sort(begin(let), end(let), [](pair<string, string> &p1, pair<string, string> &p2)
             { return (p1.second != p2.second) ? p1.second < p2.second : p1.first < p2.first; });

        for (int i = 0; i < let.size(); i++)
        {
            ans[i] = let[i].first + let[i].second;
        }

        for (int i = 0; i < dig.size(); i++)
        {
            ans[i + let.size()] = dig[i];
        }

        return ans;
    }

private:
    bool isDigitLog(string &log)
    {
        int i = 0;

        while (log[i] != ' ')
            i++;
        // ignore first space
        i++;

        return isdigit(log[i]);
    }
};

// Runtime: 3 ms, faster than 99.81% of C++ online submissions for Reorder Data in Log Files.
// Memory Usage: 10.6 MB, less than 92.69% of C++ online submissions for Reorder Data in Log Files.
// time complexity: O(n)
// space complexity: O(n)