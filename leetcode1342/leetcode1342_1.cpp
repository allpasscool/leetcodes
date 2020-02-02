class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> hashmap; // hashmap[num] = times
        
        for (auto n : arr) {
            ++hashmap[n];
        }
        
        vector<int> freq(arr.size() + 1); // freq[frequence] = # of val
        
        for (auto p : hashmap) {
            ++freq[p.second];
        }
        
        int count = 0;
        int ans = 0;
        
        for (int i = arr.size(); count < arr.size() / 2; i--) {
            if (count + freq[i] * i >= arr.size() / 2) {
                for (int j = 0; count < arr.size() / 2 && j < freq[i]; ++j) {
                    count += i;
                    ++ans;
                }
                
                return ans;
            }
            else {
                count += freq[i] * i;
                ans += freq[i];
            }
        }
        
        
        return ans;
    }
};


// Runtime: 180 ms, faster than 100.00% of C++ online submissions for Reduce Array Size to The Half.
// Memory Usage: 37.6 MB, less than 100.00% of C++ online submissions for Reduce Array Size to The Half.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/reduce-array-size-to-the-half/discuss/496714/Java-O(N)-solution