class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hash_set;
        for (int num: nums) {
            hash_set.insert(num);
        }
        
        int longest_streak = 0;
        
        for (int num: hash_set) {
            // head of streak
            if (hash_set.find(num - 1) == hash_set.end()) {
                int curr_num = num;
                int curr_streak = 1;
                
                while (hash_set.find(curr_num + 1) != hash_set.end()) {
                    curr_num++;
                    curr_streak++;
                }
                
                longest_streak = max(longest_streak, curr_streak);
            }
        }
        
        return longest_streak;
    }
};
// Runtime: 12 ms, faster than 69.01% of C++ online submissions for Longest Consecutive Sequence.
// Memory Usage: 10 MB, less than 82.69% of C++ online submissions for Longest Consecutive Sequence.
// time complexity: O(n + n)
// space complexity: O(n)