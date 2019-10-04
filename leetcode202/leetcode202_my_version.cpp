class Solution {
public:
    bool isHappy(int n) {
        int pre = n, now = n;
        unordered_set<int> hashset;
        hashset.insert(n);
        
        while (pre != 1) {
            int tmp = 0;
            now = pre;
            
            while (now != 0) {
                tmp += (now % 10) * (now % 10);
                now /= 10;
            }
            
            if (hashset.find(tmp) != hashset.end())
                return false;
            pre = tmp;
            hashset.insert(tmp);
        }
        
        return true;
    }
};

// Runtime: 4 ms, faster than 66.31% of C++ online submissions for Happy Number.
// Memory Usage: 8.5 MB, less than 61.54% of C++ online submissions for Happy Number.
// time complexity: O(n)
// space complexity: O(n)