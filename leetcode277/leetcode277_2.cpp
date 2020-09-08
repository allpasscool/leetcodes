class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int sum = 0;
        
        int num = 0;
        char sign = '+';
        
        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                num = num * 10 + (int)(s[i] - '0');
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i == s.length() - 1) {
                if (sign == '-')
                    st.push(-num);
                else if (sign == '+')
                    st.push(num);
                else if (sign == '*') {
                    num *= st.top();
                    st.pop();
                    st.push(num);
                }
                else if (sign == '/') {
                    num = st.top() / num;
                    st.pop();
                    st.push(num);
                }
                sign = s[i];
                num = 0;
            }
        }
        
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};

// time complexity: O(n)
// space complexity: O(n)
// Runtime: 20 ms, faster than 92.55% of C++ online submissions for Basic Calculator II.
// Memory Usage: 8.7 MB, less than 44.01% of C++ online submissions for Basic Calculator II.

// https://leetcode.com/problems/basic-calculator-ii/discuss/63003/Share-my-java-solution
// public class Solution {
// public int calculate(String s) {
//     int len;
//     if(s==null || (len = s.length())==0) return 0;
//     Stack<Integer> stack = new Stack<Integer>();
//     int num = 0;
//     char sign = '+';
//     for(int i=0;i<len;i++){
//         if(Character.isDigit(s.charAt(i))){
//             num = num*10+s.charAt(i)-'0';
//         }
//         if((!Character.isDigit(s.charAt(i)) &&' '!=s.charAt(i)) || i==len-1){
//             if(sign=='-'){
//                 stack.push(-num);
//             }
//             if(sign=='+'){
//                 stack.push(num);
//             }
//             if(sign=='*'){
//                 stack.push(stack.pop()*num);
//             }
//             if(sign=='/'){
//                 stack.push(stack.pop()/num);
//             }
//             sign = s.charAt(i);
//             num = 0;
//         }
//     }

//     int re = 0;
//     for(int i:stack){
//         re += i;
//     }
//     return re;
// }