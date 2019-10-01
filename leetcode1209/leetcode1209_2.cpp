class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> stack = {{0, '#'}};
        
        for (char c: s) {
            if (stack.back().second != c) {
                stack.push_back({1, c});
            }
            else {
                ++stack.back().first;
            }
            
            if (stack.back().first == k) {
                stack.pop_back();
            }
        }
        
        string output;
        
        for (auto p: stack) {
            output += string(p.first, p.second);
        }
        
        return output;
            
    }
};

// Runtime: 8 ms, faster than 99.56% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// Memory Usage: 10.6 MB, less than 100.00% of C++ online submissions for Remove All Adjacent Duplicates in String II.
// time complexity: O(n)
// space complexity: O(n)