class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hashmap;
        sort(deliciousness.begin(), deliciousness.end());
        
        int ans = 0;
        int power = 1;
        
        for (auto& n : deliciousness) {
            power = 1;
            
            for (int i = 0; i < 22; ++i) {
                // because deliciousness is sorted
                // there won't be any value bigger than n
                // so we can prune some cases
                if (power > 2 * n) {
                    break;
                }
                
                if(hashmap.find(power - n) != hashmap.end()) {
                // if(hashmap[power - n] > 0) {
                    ans += hashmap[power - n];
                    ans %= 1000000007;
                }
                power <<= 1;
            }
            
            hashmap[n]++;
        }
        
        return ans;
    }
};

// https://leetcode.com/problems/count-good-meals/discuss/999120/C%2B%2B-hashmap
// time complexity: O(n log n)
// space complexity: O(n)
// Runtime: 704 ms, faster than 72.17% of C++ online submissions for Count Good Meals.
// Memory Usage: 58.2 MB, less than 93.90% of C++ online submissions for Count Good Meals.