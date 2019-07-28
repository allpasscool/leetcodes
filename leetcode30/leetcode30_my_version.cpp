class Solution {
public:
    bool concatAllWords(string& s, vector<string>& words){
        if(words.size() == 0){
            return true;
        } else if( s.length() < (words.size() * words[0].length())){
            return false;
        }
        
        // for(int i = 0; i < s.length(); i++){
        // if(s.length() < words[0].length()){
        //     return false;
        // }
        unordered_map<string, int> hash_map;
        for(int j = 0; j < words.size(); j++){
            if(hash_map.find(words[j]) == hash_map.end()){
                hash_map[words[j]] = 1;
            } else{
                hash_map[words[j]] += 1;
            }
        }
        
        bool match_first_word = false;
        int i = 0;
        
        while(words.size() > 0){
            string next_word = "";
            for(int j = 0; j < words[0].length(); j++){
                next_word += s[i+j];
            }
            
            if(hash_map.find(next_word) != hash_map.end() && hash_map[next_word] > 0){
                hash_map[next_word] -= 1;
                words.pop_back();
                i += next_word.length();
            } else{
                return false;
            }
            
//             for(int j = 0; j < words.size(); j++){
//                 if(s[i] == words[j][0]){
//                     match_first_word = true;

//                     for(int k = 0; k < words[j].length(); k++){
//                         if(s[i+k] != words[j][k]){
//                             match_first_word = false;
//                             break;
//                         }
//                     }

//                     if(match_first_word){
//                         // words.erase(words.begin() + j);
//                         // int start = words[j].length();
//                         // s = s.substr(start, s.length() - start);
//                         // return concatAllWords(s, words);

//                         i += words[j].length();
//                         words.erase(words.begin() + j);
//                         break;
//                     }
//                 }
//             }
            
//             if(!match_first_word){
//                 return false;
//             }
//             match_first_word = false;
        }
        
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        if(s.length() == 0 || words.size() == 0){
            return vector<int> {};
        }
        
        vector<int> output;
        bool match_first_word;
        sort(words.begin(), words.end());
        
        bool reduendent = false;
        
        for(int i = 0; i < s.length(); i++){
            if((s.length() - i) < (words.size() * words[0].length())){
                return output;
            }
            reduendent = false;
            
            for(int j = 0; j < words.size(); j++){
                if(s[i] == words[j][0]){
                    match_first_word = true;
                    
                    //reduend first word?
                    if(j != 0){
                        reduendent = true;
                        for(int k = 0; k < words[j].length(); k++){
                            if(words[j-1][k] != words[j][k]){
                                reduendent = false;
                                break;
                            }
                        }
                    }
                    
                    if(reduendent){
                        continue;
                    }
                    
                    //match first word?
                    for(int k = 0; k < words[j].length(); k++){
                        if(s[i+k] != words[j][k]){
                            match_first_word = false;
                            break;
                        }
                    }
                    
                    if(match_first_word){
                        vector<string> last_words = words;
                        int start = i + words[j].length();
                        last_words.erase(last_words.begin() + j);
                        string sub_s = s.substr(start, s.length() - start);
                        bool concat_all_words = concatAllWords(sub_s, last_words);
                        
                        if(concat_all_words){
                            output.push_back(i);
                            break;
                        }
                    }
                }
            }
        }
        
        return output;
    }
};
// Runtime: 496 ms, faster than 20.54% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 165 MB, less than 18.23% of C++ online submissions for Substring with Concatenation of All Words.
// time complexity: O(m log m + n * m * k * ((m-1) + (n-k))), n is length of s, m is size of words, k is the length of each word
// space complexity: O(n + m)