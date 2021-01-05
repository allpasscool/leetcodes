class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        unordered_map<int, int> hashmap;
        
        int ans = 0;
        int power = 1;
        
        for (auto& n : deliciousness) {
            power = 1;
            
            for (int i = 0; i < 22; ++i) {
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

// time comlexity: O(n)
// space complexity: O(n)
// Runtime: 1156 ms, faster than 37.95% of C++ online submissions for Count Good Meals.
// Memory Usage: 58.3 MB, less than 83.14% of C++ online submissions for Count Good Meals.