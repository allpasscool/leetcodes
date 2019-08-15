class Solution {
public:
    int numJewelsInStones(string J, string S) {
        std::unordered_set<char> J_set;
        
        for (int i = 0; i < J.length(); i++) {
            J_set.insert(J[i]);
        }
        
        int count = 0;
        
        for (int i = 0; i < S.length(); i++) {
            if (J_set.find(S[i]) != J_set.end()){
                count++;
            }
        }
        
        return count;
    }
};
// Runtime: 4 ms, faster than 65.33% of C++ online submissions for Jewels and Stones.
// Memory Usage: 8.7 MB, less than 28.75% of C++ online submissions for Jewels and Stones.
// time complexity: O(S+J)
// space complexity: O(J)

//find in set is O(log n), in unordered_set is O(1)