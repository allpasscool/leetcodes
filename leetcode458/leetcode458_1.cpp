class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int states = minutesToTest / minutesToDie + 1;//each pig has states, alive, dead after 1, or 2 ...
        
        //states^pig >= bucket
        return ceil(log(buckets) / log(states));
    }
};
// Runtime: 0 ms, faster than 100.00% of C++ online submissions for Poor Pigs.
// Memory Usage: 8.3 MB, less than 100.00% of C++ online submissions for Poor Pigs.
// time complexity: O(1)
// space complexity: O(1)