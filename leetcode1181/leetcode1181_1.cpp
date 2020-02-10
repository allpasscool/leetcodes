class Solution {
public:
    vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
        unordered_map<string, set<string>> first, last;
        
        set<string> res;
        
        for (auto p : phrases) {
            auto fp = p.find(' '), lp = p.rfind(' ');
            fp = fp == string::npos ? p.size() : fp;
            lp = lp == string::npos ? 0 : lp + 1;
            
            for (auto s : first[p.substr(lp)])
                res.insert(p + s);
            
            for (auto s : last[p.substr(0, fp)])
                res.insert(s + p);
            
            first[p.substr(0, fp)].insert(p.substr(fp));
            last[p.substr(lp)].insert(p.substr(0, lp));
        }
        
        return vector<string> (begin(res), end(res));
    }
};


// Runtime: 12 ms, faster than 81.39% of C++ online submissions for Before and After Puzzle.
// Memory Usage: 13.7 MB, less than 100.00% of C++ online submissions for Before and After Puzzle.
// time complexity: O(n^2)
// space complexity: O(n)
// https://leetcode.com/problems/before-and-after-puzzle/discuss/377944/C%2B%2B-2-hash-maps-and-set

// vector<string> beforeAndAfterPuzzles(vector<string>& phrases) {
//   unordered_map<string, set<string>> first, last;
//   set<string> res;
//   for (auto p : phrases) {
//     auto fp = p.find(' '), lp = p.rfind(' ');
//     fp = fp == string::npos ? p.size() : fp;
//     lp = lp == string::npos ? 0 : lp + 1;
//     for (auto pp : first[p.substr(lp)]) res.insert(p + pp);
//     for (auto pp : last[p.substr(0, fp)]) res.insert(pp + p);
//     first[p.substr(0, fp)].insert(p.substr(fp));
//     last[p.substr(lp)].insert(p.substr(0, lp));
//   }
//   return vector<string>(begin(res), end(res));
// }