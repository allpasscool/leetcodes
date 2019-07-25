class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        string str;
        
        addingParthenthesis(output, str, n, n);
        return output;
    }
    
    void addingParthenthesis(vector<string>& output, string& str, int left, int right){
        if(left == 0 && right == 0){
            output.push_back(str);
            return;
        }
        
        if(left > 0){
            str += "(";
            addingParthenthesis(output, str, left-1, right);
            str.pop_back();
        }
        
        if(right > left){
            str += ")";
            addingParthenthesis(output, str, left, right-1);
            str.pop_back();
        }
    }
};
// Runtime: 4 ms, faster than 90.66% of C++ online submissions for Generate Parentheses.
// Memory Usage: 13.7 MB, less than 87.43% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^n)
// space complexity: O(2^n)