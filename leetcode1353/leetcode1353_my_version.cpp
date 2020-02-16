class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(begin(events), end(events), comp);
        
        // int cur = 1;
        unordered_set<int> used;
        int count = 0;
        int n = events.size();
        int i = 0;
        
        while (i < n) {
            for (int j = events[i][0]; j <= events[i][1]; ++j) {
                if (used.find(j) == used.end()) {
                    used.insert(j);
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


// Runtime: 268 ms, faster than 54.55% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// Memory Usage: 56.4 MB, less than 100.00% of C++ online submissions for Maximum Number of Events That Can Be Attended.
// time complexity: O(n log n + n * m), m is the length of longest events
// space complexity: O(n)