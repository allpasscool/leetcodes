class Solution {
public:
    string num_to_alpha[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        
        if(digits.empty()){
            return result;
        }
        
        char cur_digit = digits[0];
        string cur_str = num_to_alpha[cur_digit - '2'];
        
        vector<string> sub_result = letterCombinations(digits.substr(1));
        
        if(sub_result.empty()){
            sub_result.emplace_back("");
        }
        
        for(int i = 0; i < cur_str.length(); i++){
            for(int j = 0; j < sub_result.size(); j++){
                string tmp = "";
                
                tmp += cur_str[i];
                tmp += sub_result[j];
                result.emplace_back(tmp);
            }
            
        }
        
        return result;
    }
};
// Runtime: 4 ms, faster than 72.13% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 8.5 MB, less than 80.85% of C++ online submissions for Letter Combinations of a Phone Number.
// time complexity: O(n^3)
// space complexity: O(n^3)