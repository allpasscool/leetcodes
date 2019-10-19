class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        this->reset();
        this->recurse(s, 0, 0, 0, "", 0);
        vector<string> output;
        
        for (auto s: this->valid_expressions)
            output.push_back(s);
        
        return output;
    }
private:
    unordered_set<string> valid_expressions;
    int min_num_removed;
    
    void reset() {
        this->valid_expressions.clear();
        this->min_num_removed = INT_MAX;
    }
    
    void recurse (string& s, int index, int left_count, int right_count,
                 string expression, int removed_count) {
        // If we have reached the end of string
        if (index == s.length()) {
            // If the current expression is valid.
            if (left_count == right_count) {
                // If the current count of removed parenthese is <= the current minimum count
                if (removed_count <= this->min_num_removed) {
                    // If the current count beats the overal minimum we have till now
                    if (removed_count < this->min_num_removed) {
                        this->valid_expressions.clear();
                        this->min_num_removed = removed_count;
                    }
                    
                    this->valid_expressions.insert(expression);
                }
            }
        }
        else {
            char curr = s[index];
            int length = expression.length();
            
            // If the current character is neither an opening bracket nor a closing one,
            // simply recurse further by adding it to the expression expression
            if (curr != '(' && curr != ')') {
                expression += curr;
                this->recurse(s, index + 1, left_count, right_count, expression, removed_count);
            }
            else {
                // recursion where we delete the current character and move forward
                this->recurse(s, index + 1, left_count, right_count, expression, removed_count + 1);
                expression += curr;
                
                // If it's an opening parenthesis, consider it and recurse
                if (curr == '(') {
                    this->recurse(s, index + 1, left_count + 1, right_count, expression, removed_count);
                }
                else if (right_count < left_count) {
                    // For a closing parenthesis, only recurse if right < left
                    this->recurse(s, index + 1, left_count, right_count + 1, expression, removed_count);
                }
                
                // Undoing the append operation for other recursions
                // expression.erase(length);
            }
        }
    }
};
// Runtime: 208 ms, faster than 10.76% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 40.1 MB, less than 8.33% of C++ online submissions for Remove Invalid Parentheses.
// time complexity: O(2^n)
// space complexity: O(n^2)