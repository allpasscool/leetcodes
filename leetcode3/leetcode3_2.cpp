class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::unordered_set<char> charSet;
        int n = s.length();
        int ans = 0, i = 0, j = 0;
        while(i < n && j < n){
            //try to extend the range [i, j]
            if(charSet.find(s[j]) == charSet.end()){
                charSet.insert(s[j]);
                j++;
                ans = std::max(ans, j - i);
            }
            else{
                charSet.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};