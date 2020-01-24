class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> sums; // A + B
        
        for (auto a : A) {
            for (auto b : B) {
                ++sums[a + b];
            }
        }
        
        int ans = 0;
        
        for (auto c : C) {
            for (auto d : D) {
                int rest = -(c + d);
                
                if (sums.find(rest) != sums.end()) {
                    ans += sums[rest];
                }
            }
        }
        
        return ans;
    }
};


// Runtime: 148 ms, faster than 91.73% of C++ online submissions for 4Sum II.
// Memory Usage: 28.6 MB, less than 72.73% of C++ online submissions for 4Sum II.
// time complexity: O(n^2)
// space complexity: O(n^2)
// https://zxi.mytechroad.com/blog/hashtable/leetcode-454-4sum-ii/