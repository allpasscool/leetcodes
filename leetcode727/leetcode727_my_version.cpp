class Solution {
public:
    string minWindow(string s1, string s2) {
        string ans = "";
        int n = s1.size(), m = s2.size();
        
        for (int i = 0; i < n; i++)
        {
            if (s1[i] == s2[0])
            {
                int n1 = i, n2 = 0;
                
                while (n2 < m && n1 < n)
                {
                    if (s1[n1] == s2[n2])
                    {
                        n1++;
                        n2++;
                    }
                    else
                    {
                        n1++;
                    }
                    
                    if (ans.size() != 0 && n1 - i > ans.size())
                        break;
                }
                
                if (n2 == m && ans.size() == 0)
                    ans = s1.substr(i, n1 - i);
                else if (n2 == m && ans.size() != 0 && (n1 - i) < ans.size())
                    ans = s1.substr(i, n1 - i);
            }
        }
        
        return ans;
    }
};

// Time Limit Exceeded
// time complexity: O(n^2)
// space complexity: O(n)