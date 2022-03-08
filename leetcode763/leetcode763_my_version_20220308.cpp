class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        // {left, right}
        vector<pair<int, int>> let(26, {INT_MAX, INT_MIN});
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
        {
            int c = s[i] - 'a';
            let[c].first = min(let[c].first, i);
            let[c].second = max(let[c].second, i);
        }

        sort(begin(let), end(let), [](pair<int, int> &p1, pair<int, int> &p2)
             { return p1.first != p2.first ? p1.first < p2.first : p1.second < p2.second; });

        // merge interval
        int start = let[0].first, end = let[0].second;

        for (int i = 0; i < 26; i++)
        {
            // doesn't exist
            if (let[i].first == INT_MAX)
                continue;

            if (let[i].first > end)
            {
                ans.push_back(end - start + 1);
                start = let[i].first;
                end = let[i].second;
            }
            else
                end = max(end, let[i].second);
        }

        // last interval
        ans.push_back(end - start + 1);

        return ans;
    }
};

// Runtime: 3 ms, faster than 86.34% of C++ online submissions for Partition Labels.
// Memory Usage: 6.6 MB, less than 87.17% of C++ online submissions for Partition Labels.
// time complexity: O(26 log 26 + n)
// space complexity: O(1)