class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_of_string;
        
        for(int i = 0; i < s.length(); i++){
            if(stack_of_string.empty()){
                stack_of_string.push(s[i]);
            }
            else{
                switch (s[i])
                {                        
                    case '(':
                    case '[':
                    case '{':
                        stack_of_string.push(s[i]);
                        break;
                    case ')':
                        if(stack_of_string.top() != '('){
                            return false;
                        }
                        else{
                            stack_of_string.pop();
                            break;
                        }
                    case ']':
                        if(stack_of_string.top() != '['){
                            return false;
                        }
                        else{
                            stack_of_string.pop();
                            break;
                        }
                    case '}':
                        if(stack_of_string.top() != '{'){
                            return false;
                        }
                        else{
                            stack_of_string.pop();
                            break;
                        }                                   
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
// Memory Usage: 8.6 MB, less than 28.80% of C++ online submissions for Valid Parentheses.
// time complexity:O(n)
// space complexity: O(n)