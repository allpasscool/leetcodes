class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> output;
        
        if(digits.length() == 0){
            return output;
        }
        
        string num_to_alpha[8] = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        
        output.emplace_back("");
        
        for(int i = 0; i < digits.length(); i++){
            
            vector<string> tmp;
            string next = num_to_alpha[digits[i] - '2'];
            
            for(int j = 0; j < next.length(); j++){
                for(int k = 0; k < output.size(); k++){
                    tmp.emplace_back(output[k] + next[j]);
                }
            }
            
            output = tmp;
        }
        
        return output;
    }
};
// Runtime: 4 ms, faster than 70.76% of C++ online submissions for Letter Combinations of a Phone Number.
// Memory Usage: 8.4 MB, less than 83.66% of C++ online submissions for Letter Combinations of a Phone Number.
// time complexity: O(n^3)
// space complexity: O(n^3)