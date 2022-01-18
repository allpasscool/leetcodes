class Solution
{
public:
    int wordCount(vector<string> &startWords, vector<string> &targetWords)
    {
        int ans = 0;
        vector<bool> valid(targetWords.size());
        vector<vector<bool>> target(targetWords.size(), vector<bool>(26));
        int minTarget = INT_MAX;
        int maxTarget = INT_MIN;

        for (int i = 0; i < targetWords.size(); i++)
        {
            if (targetWords[i].size() < minTarget)
                minTarget = targetWords[i].size();
            if (targetWords[i].size() > maxTarget)
                maxTarget = targetWords[i].size();
            for (int j = 0; j < targetWords[i].size(); j++)
            {
                char c = targetWords[i][j];
                target[i][c - 'a'] = true;
            }
        }

        for (int i = 0; i < startWords.size(); i++)
        {
            if (startWords[i].size() < minTarget - 1 || startWords[i].size() >= maxTarget)
                continue;

            vector<bool> start(26);

            for (int k = 0; k < startWords[i].size(); k++)
            {
                start[startWords[i][k] - 'a'] = true;
            }

            for (int j = 0; j < targetWords.size(); j++)
            {
                if (valid[j] || (targetWords[j].size() != (startWords[i].size() + 1)))
                    continue;

                int diff = 0;
                bool invalid = false;
                for (int k = 0; k < 26; k++)
                {
                    if (start[k] && !target[j][k])
                    {
                        invalid = true;
                        break;
                    }

                    if (!start[k] && target[j][k])
                        diff++;
                }

                if (!invalid && diff == 1)
                {
                    valid[j] = true;
                }
            }
        }

        for (int i = 0; i < valid.size(); i++)
        {
            if (valid[i])
                ans++;
        }

        return ans;
    }
};

// time complexity: O(t * m + s * n * t * 26),
// t is size of target words, s is size of start words,
// m is the max len of target word, n is the max len of start word
// space complexity: O(t + s)
// Time Limit Exceeded