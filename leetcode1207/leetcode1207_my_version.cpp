class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> hashmap;
        
        for (auto n: arr)
            ++hashmap[n];
        
        unordered_map<int, int> occur;
        
        for (auto p: hashmap) {
            int fre = p.second;
            
            if (occur[fre] != 0) 
                return false;
            occur[fre] = 1;
        }
        
        return true;
    }
};

// Runtime: 4 ms, faster than 75.00% of C++ online submissions for Unique Number of Occurrences.
// Memory Usage: 8.8 MB, less than 100.00% of C++ online submissions for Unique Number of Occurrences.
// time complexity: O(n)
// space complexity: O(n)