class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_of_string;
        
        if(s.length() == 0){
            return true;
        }
        else if(s.length() % 2 == 1){
            return false;
        }
        
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '{'){
                stack_of_string.push('}');
            }
            else if(s[i] == '['){
                stack_of_string.push(']');
            }
            else if(s[i] == '('){
                stack_of_string.push(')');
            }
            else{
                if(stack_of_string.empty() || stack_of_string.top() != s[i]){
                    return false;
                }
                else{
                    stack_of_string.pop();
                }
            }
        }
        
        if(!stack_of_string.empty()){
            return false;
        }
        
        return true;
    }
};
// Runtime: 4 ms, faster than 70.08% of C++ online submissions for Valid Parentheses.
// Memory Usage: 8.4 MB, less than 79.85% of C++ online submissions for Valid Parentheses.
// time complexity: O(n)
// space complexity: O(n)