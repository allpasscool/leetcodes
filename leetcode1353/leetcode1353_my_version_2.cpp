class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events), comp);
        
        vector<bool> used(1e5 + 1);
        int count = 0;
        int n = events.size();
        int i = 0;
        
        while (i < n) {
            for (int j = events[i][0]; j <= events[i][1]; ++j) {
                if (!used[j]) {
                    used[j] = true;
                    ++count;
                    break;
                }
            }
            ++i;
        }
        
        return count;
    }
private:
    static bool comp(vector<int>& n1, vector<int>& n2) {
        return n1[1] < n2[1] || (n1[1] == n2[1] && n1[0] < n2[0]);
    }
};


// Runtime: 228 ms, faster than 81.82% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// Memory Usage: 46.2 MB, less than 100.00% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// time complexity: O(n log n + n * m), m is the length of longest events
// space complexity: O(n)