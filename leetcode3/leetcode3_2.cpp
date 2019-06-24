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
//Runtime: 36 ms
//Memory Usage: 929.8 KB
//Time complexity : O(2n)=O(n). In the worst case each character will be visited twice by i and j.
//Space complexity : O(min(m,n)). 
//Same as the previous approach. We need O(k) space for the sliding window, where kk is the size of the Set.
// The size of the Set is upper bounded by the size of the string nn and the size of the charset/alphabet m. 