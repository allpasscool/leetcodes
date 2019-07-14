class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size() >= 3){//s = "aaaaaaaaaaaaab" , p = "a*a*a*a*a*a*a*a*a*a*c"
            if(p[0] == p[2] && p[1] == '*' && p[3] == '*'){
                return isMatch(s, p.substr(2, p.size() - 2));
            }
        }
//         if(p.size() >= 3 && p[0] == p[2] && p[1] == '*' && p[3] == '*'){
//             int i = 0;
//             for(; i <= p.size() - 4; i += 2){
//                 if(p[i+0] != p[i+2] || p[i+1] != '*' || p[i+3] != '*'){
//                     i += 2;
//                     break;
//                 }
//             }
            
//             i -= 2;
//             if(p[i] == p[i+2] && p[i+1] == '*' && p[i+3] == '*'){
//                 return isMatch(s, p.substr(i+2, p.size() - (i + 2)));
//             }
//             else{
//                 return isMatch(s, p.substr(i, p.size() - i));
//             }
//         }
        
        
        //both empty
        if(s.size() == 0 && p.size() == 0){
            return true;
        }
        else if(p.size() == 0){//p is empty
            return false;
        }
        else if(s.size() == 0){//s is empty
            
            if(p.size() % 2 != 0){
                return false;
            }
            
            for(int i = 1; i < p.size(); i += 2){
                if(p[i] != '*'){
                    return false;
                }
            }
            
            //s = '' and p = "a*b*c*"
            return true;
        }
        
        
        if(s.size() == 1){
            if(p.size() > 1){//p = a , s = ab*... or s = .b*
                if((p[0] == s[0] || p[0] == '.') && p.size() >= 3 && p[2] == '*'){
                    return isMatch(s.substr(0, 0), p.substr(1, p.size() - 1));
                }
                else if(p[1] == '*'){// s = c*....
                    if(s[0] == p[0] || p[0] == '.'){
                        return isMatch("", p.substr(2, p.size() - 2)) || isMatch(s, p.substr(2, p.size() - 2));
                    }
                    else{
                        return isMatch(s, p.substr(2, p.size() - 2));
                    }
                }
                else{
                    return false;
                }
            }
            else{
                if(p[0] == s[0] || p[0] == '.'){
                    return true;
                }
                else{
                    return false;
                }
            }
        }
        
        
        if(p[0] == '.' || s[0] == p[0]){
            if(p[1] == '*'){
                return isMatch(s.substr(1, s.size() - 1), p) || isMatch(s.substr(1, s.size() -1), p.substr(2, p.size() - 2)) || isMatch(s, p.substr(2, p.size() - 2));
            }
            else{
                return isMatch(s.substr(1, s.size() - 1), p.substr(1, p.size() - 1));
            }
        }
        else if(p[1] == '*'){
            return false || isMatch(s, p.substr(2, p.size() - 2));
        }
        else{
            return false;
        }
        
    }
};
// Runtime: 52 ms, faster than 31.04% of C++ online submissions for Regular Expression Matching.
// Memory Usage: 16.6 MB, less than 8.20% of C++ online submissions for Regular Expression Matching.
//time complexity: O(3^n)
//space complexity: O(3^n)