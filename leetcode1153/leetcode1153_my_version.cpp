class Solution {
public:
    bool canConvert(string str1, string str2) {
        unordered_map<char, char> match;
        unordered_set<char> checked;
        int n = str1.size();
        int conversionCnt = 0;
        
        for (int i = 0; i < n; i++)
        {
            if (match.find(str1[i]) == match.end())
            {
                match[str1[i]] = str2[i];
                checked.insert(str2[i]);
                if (str1[i] != str2[i])
                    conversionCnt++;
            }
            else
            {
                // one letter only converse to another one
                // one to one match
                if (match[str1[i]] != str2[i])
                {
                    return false;
                }
            }
        }
        
        // if there is more than 26 matches from str1 -> str2
        // we have a cycle. so we can't converse str1 -> str2
        // special case is str1 == str2, so it doesn't need any conversion
        if (checked.size() > 25 && conversionCnt > 0)
            return false;
        
        return true;
    }
};

// Runtime: 8 ms, faster than 32.63% of C++ online submissions for String Transforms Into Another String.
// Memory Usage: 7.4 MB, less than 41.75% of C++ online submissions for String Transforms Into Another String.
// time complexity: O(n)
// space complexity: O(26)