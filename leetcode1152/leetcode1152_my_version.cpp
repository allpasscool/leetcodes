class Solution
{
public:
    vector<string> mostVisitedPattern(vector<string> &username, vector<int> &timestamp, vector<string> &website)
    {
        unordered_map<string, vector<pair<int, string>>> userWeb;
        unordered_map<string, int> patternScore;
        int n = username.size();

        // get user: {timestamp, web} array
        for (int i = 0; i < n; i++)
        {
            userWeb[username[i]].push_back({timestamp[i], website[i]});
        }

        // sort array by timestamp
        for (auto &p : userWeb)
        {
            vector<pair<int, string>> &v = p.second;
            sort(begin(v), end(v), [](pair<int, string> &p1, pair<int, string> &p2)
                 { return p1.first < p2.first; });
        }

        // count pattern score
        // each pattern get at most one score from one person only
        for (auto &p : userWeb)
        {
            vector<pair<int, string>> &webs = p.second;
            int m = webs.size();
            unordered_set<string> checked;

            // calculate all combination
            for (int i = 0; i < (m - 2); i++)
            {
                for (int j = i + 1; j < (m - 1); j++)
                {
                    for (int k = j + 1; k < m; k++)
                    {
                        string pattern = webs[i].second + "_" + webs[j].second + "_" + webs[k].second + "_";
                        if (checked.find(pattern) != checked.end())
                            continue;
                        patternScore[pattern]++;
                        checked.insert(pattern);
                    }
                }
            }
        }

        string winner;
        int maxCount = 0;

        for (auto &p : patternScore)
        {
            if (p.second > maxCount)
            {
                winner = p.first;
                maxCount = p.second;
            }
            else if (p.second == maxCount && p.first < winner)
                winner = p.first;
        }

        vector<string> ans;
        int start = 0;

        for (int i = 0; i < winner.size(); i++)
        {
            if (winner[i] == '_')
            {
                ans.push_back(winner.substr(start, i - start));
                start = i + 1;
            }
        }

        return ans;
    }
};

// Runtime: 36 ms, faster than 78.81% of C++ online submissions for Analyze User Website Visit Pattern.
// Memory Usage: 17.5 MB, less than 84.27% of C++ online submissions for Analyze User Website Visit Pattern.
// time complexity: O(n log n + n^3)
// space complexity: O(n)