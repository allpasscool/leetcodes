class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int s_len = s.length(), words_num = words.size();
        vector<int> output;
        
        if(s_len == 0 || words_num == 0){
            return output;
        }
        
        int word_len = words[0].length();
        unordered_map<string, int> hash_map_words;
        
        //put words into hash map
        for(string& word: words){
            hash_map_words[word]++;
        }
        
        for(int i = 0; i < word_len; i++){
            int start = i, count = 0;
            unordered_map<string, int> current_hash_map;
            
            for(int j = i; j <= s_len - word_len; j += word_len){
                string next_word = s.substr(j, word_len);
                
                //this might be the word we are looking for
                if(hash_map_words.count(next_word)){
                    current_hash_map[next_word]++;
                    
                    if(current_hash_map[next_word] <= hash_map_words[next_word]){
                        count++;
                    } else{
                        count++;
                        //too many this word, remove words until not too many
                        while(current_hash_map[next_word] > hash_map_words[next_word]){
                            string tmp_word = s.substr(start, word_len);
                            current_hash_map[tmp_word]--;
                            count--;
                            start += word_len;
                        }
                    }
                    
                    if(count == words_num){
                        output.push_back(start);
                        current_hash_map[s.substr(start, word_len)]--;
                        count--;
                        start += word_len;
                    }
                } else{//not a valid word
                    current_hash_map.clear();
                    count = 0;
                    start = j + word_len;
                }
            }
        }
        return output;
    }
};
// Runtime: 24 ms, faster than 95.39% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 14.7 MB, less than 89.66% of C++ online submissions for Substring with Concatenation of All Words.
// time complexity: O(n), n is the length of s and m is the size of words
// space complexity: O(m)