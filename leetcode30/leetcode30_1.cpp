class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.size() == 0 || s.length() == 0){
            return vector<int> {};
        }
        
        int s_len = s.length(), word_len = words[0].length(), words_num = words.size();
        
        unordered_map<string, int> hash_map_words;;
        
        //get all words into hash map
        for(string& word: words){
            if(hash_map_words.find(word) == hash_map_words.end()){
                hash_map_words[word] = 1;
            } else{
                hash_map_words[word]++;
            }
        }
        
        vector<int> output;
        bool is_concate_all_words;
        
        for(int i = 0; i <= s_len - word_len * words_num; i++){
            unordered_map<string, int> current_hash_map;
            is_concate_all_words = true;
            
            for(int j = 0; j < words_num; j++){
                string next_word = s.substr(i + j * word_len, word_len);

                //not the word we are looking for
                if(hash_map_words.find(next_word) != hash_map_words.end()){
                    if(current_hash_map.find(next_word) == current_hash_map.end()){
                        current_hash_map[next_word] = 1;
                    } else{
                        current_hash_map[next_word]++;

                        if(current_hash_map[next_word] > hash_map_words[next_word]){
                            is_concate_all_words = false;
                            break;      
                        }
                    }
                } else{
                    is_concate_all_words = false;
                    break;
                }
            }
            
            if(is_concate_all_words){
                output.push_back(i);
            }
        }
        
        return output;
    }
};
// Runtime: 244 ms, faster than 33.21% of C++ online submissions for Substring with Concatenation of All Words.
// Memory Usage: 21.3 MB, less than 61.39% of C++ online submissions for Substring with Concatenation of All Words.
// time complexity: O(n * m), n is the length of s and m is the size of words
// space complexity: O(m)