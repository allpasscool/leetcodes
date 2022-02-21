class Solution
{
public:
    string minRemoveToMakeValid(string s)
    {
        vector<char> newS;
        int count = 0;

        // remove invalid )
        for (char c : s)
        {
            if (c == ')')
            {
                if (count == 0)
                    continue;
                else
                {
                    count--;
                    newS.push_back(c);
                }
            }
            else if (c == '(')
            {
                count++;
                newS.push_back(c);
            }
            else
                newS.push_back(c);
        }

        count = 0;
        // remove invalid (
        for (int i = newS.size() - 1; i >= 0; i--)
        {
            if (newS[i] == '(')
            {
                if (count == 0)
                    newS[i] = 'X';
                else
                {
                    count--;
                }
            }
            else if (newS[i] == ')')
            {
                count++;
            }
        }

        string ans;
        for (int i = 0; i < newS.size(); i++)
        {
            if (newS[i] != 'X')
                ans += newS[i];
        }

        return ans;
    }
};

// Runtime: 24 ms, faster than 78.26% of C++ online submissions for Minimum Remove to Make Valid Parentheses.
// Memory Usage: 12.3 MB, less than 17.02% of C++ online submissions for Minimum Remove to Make Valid
// time complexity: O(n)
// space complexity: O(n)