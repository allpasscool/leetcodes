class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string subS;
        string longestS = "";
        for(int i = 0; i < s.length(); i++){
            subS = "";
            for(int j = i; j < s.length(); j++){
                if(subS.find(s[j]) != std::string::npos){
                    //cout << "break" << endl;
                    break;
                }
                else{
                    subS = subS + s[j];
                }
            }
            //cout << subS.size() << endl;
            if(subS.size() > longestS.size()){
                longestS = subS;
            }
        }
        
        return longestS.size();
    }
};
//Runtime: 380 ms
//Memory Usage: 913.4 KB
//time: O(n^2)
//space: O(s + subs + longestS)