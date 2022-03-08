class Solution
{
public:
    vector<int> partitionLabels(string s)
    {
        vector<int> last(26);
        vector<int> ans;

        for (int i = 0; i < s.size(); i++)
            last[s[i] - 'a'] = i;

        int maxRight = 0, left = 0;
        for (int i = 0; i < s.size(); i++)
        {
            maxRight = max(maxRight, last[s[i] - 'a']);

            if (i == maxRight)
            {
                ans.push_back(maxRight - left + 1);
                left = i + 1;
            }
        }

        return ans;
    }
};

// Runtime: 8 ms, faster than 33.13% of C++ online submissions for Partition Labels.
// Memory Usage: 6.7 MB, less than 63.67% of C++ online submissions for Partition Labels.
// time complexity : O(2 * n)
// space complexity: O(1)