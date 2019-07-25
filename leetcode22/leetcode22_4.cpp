class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> output;
        
        addingParthenthesis(output, "", n, n);
        return output;
    }
    
    void addingParthenthesis(vector<string>& output, string str, int left, int right){
        if(left == 0 && right == 0){
            output.push_back(str);
            return;
        }
        
        if(left > 0){
            addingParthenthesis(output, str + "(", left-1, right);
        }
        
        if(right > left){
            addingParthenthesis(output, str+ ")", left, right-1);
        }
    }
};
// Runtime: 4 ms, faster than 90.66% of C++ online submissions for Generate Parentheses.
// Memory Usage: 17.2 MB, less than 47.06% of C++ online submissions for Generate Parentheses.
// time complexity: O(2^n)
// space complexity: O(2^n)