class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string current (2 * n, ' ');//initialize string to n length space chars
        generateAll(current, 0, output);
        return output;
    }
    
    void generateAll(string current, int pos, vector<string>& result){
        if(pos == current.length()){
            if(valid(current)){
                result.push_back(current);
            }
        }
        else{
            current[pos] = '(';
            generateAll(current, pos+1, result);
            current[pos] = ')';
            generateAll(current, pos+1, result);
        }
    }
    
    bool valid(string &current){
        int balance = 0;
        for(char const &c: current){
            if(c == '('){
                balance++;
            }
            else{
                balance--;
                if(balance < 0){
                    return false;
                }
            }
        }
        
        return (balance == 0);
    }
};
// Runtime: 76 ms, faster than 5.01% of C++ online submissions for Generate Parentheses.
// Memory Usage: 60.8 MB, less than 5.01% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^(2n) * n)
// space complexity: O(2^(2n) * n) Naively, every sequence could be valid. 