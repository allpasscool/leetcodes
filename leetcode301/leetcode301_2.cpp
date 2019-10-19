class Solution {
public:
  vector<string> removeInvalidParentheses(string s) {
    int left = 0, right = 0;
    for (char ch : s) {
      if (ch == '(') {
        ++left;
      } else if (ch == ')') {
        if (left > 0) {
          --left;
        } else {
          ++right;
        }
      }
    }
    res.clear();
    dfs(s, 0, left, right, 0, "");
    return res;
  }
  
private:
  void dfs(const string& s, int start, int left, int right, 
           int open, string path) {
    if (start == s.length()) {
      if (left == 0 && right == 0 && open == 0) {
        res.push_back(path);
      }
      return;
    }
    if (left < 0 || right < 0 || open < 0) return;
    
    char c = s[start];
    if (c == '(') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= left; ++i) {
          dfs(s, start + i + 1, left - i - 1, right, open, path);
        }
      }
      
      dfs(s, start + 1, left, right, open + 1, path + c);
    } else if (c == ')') {
      if (start == 0 || s[start - 1] != c) {
        for (int i = 0; start + i < s.length() && s[start + i] == c && i + 1 <= right; ++i) {
          dfs(s, start + i + 1, left, right - i - 1, open, path);
        }
      }      
      
      dfs(s, start + 1, left, right, open - 1, path + c);
    } else {
      dfs(s, start + 1, left, right, open, path + c);
    }
  }

  vector<string> res;
};

// Runtime: 4 ms, faster than 92.89% of C++ online submissions for Remove Invalid Parentheses.
// Memory Usage: 13.6 MB, less than 45.83% of C++ online submissions for Remove Invalid Parentheses.
// time complexity: O(2^n
// space complexity: O(left * right * n)
// https://leetcode.com/problems/remove-invalid-parentheses/discuss/75050/My-C%2B%2B-DFS-Solution-16ms