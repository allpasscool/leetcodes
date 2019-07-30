class Solution {
public:
    int longestValidParentheses(string s) {
        //longest_valid parentheses, count '(' ')', longest_now from index 'start'
        int longest_valid = 0, count = 0, longest_now = 0, start = 0;
        
        for(int i = 0; i < s.length(); i++){
            
            if(s[i] == '('){
                count++;
            } else if(s[i] == ')'){
                count--;
            }
            longest_now++;
            
            // too many ')'
            if(count < 0){
                longest_now--;
                count = 0;
                
                if(longest_now > longest_valid){
                    longest_valid = longest_now;
                }
                
                longest_now = 0;
                start = i + 1;
            } else if(count == 0){
                if(longest_now > longest_valid){
                    longest_valid = longest_now;
                }
            }
        }
        
        int end = s.length() - 1;
        if(count == 0){//valid parentheses
            if(longest_now > longest_valid){
                longest_valid = longest_now;
            }
            
        } else if(count > 0 && longest_now > longest_valid){//too many '('
            while(end - start + 1 > longest_valid){//while longest_now might have longer valid parentheses
                int tmp_count = 0;
                
                for(int i = end; i >= start; i--){
                    if(s[i] == ')'){
                        tmp_count--;
                    } else if(s[i] == '('){
                        tmp_count++;
                    }
                    
                    if(tmp_count > 0){
                        if(end - i > longest_valid){//(i+1) - end
                            longest_valid = end - i;
                        }
                        
                        end = i - 1;
                        count--;
                        
                        if(count == 0){
                            //start - (i-1), i, (i+1) - end
                            if(i - start > longest_valid){
                                longest_valid = i - start;
                            }
                            
                            return longest_valid;
                        } else{
                            break;
                        }
                    }

                }
            }
        }
        
        return longest_valid;
    }
};
// Runtime: 4 ms, faster than 96.87% of C++ online submissions for Longest Valid Parentheses.
// Memory Usage: 9.1 MB, less than 85.30% of C++ online submissions for Longest Valid Parentheses.
// time complexity: O(n)
// space complexity: O(1)
