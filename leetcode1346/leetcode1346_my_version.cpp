class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> hashset;
        
        for (auto n : arr) {
            if (hashset.find(2 * n) != hashset.end()) {
                return true;
            }
            else if (n % 2 == 0 && hashset.find(n / 2) != hashset.end()) {
                return true;
            }
            
            hashset.insert(n);
        }
        
        return false;
    }
};


// Runtime: 8 ms, faster than 100.00% of C++ online submissions for Check If N and Its Double Exist.
// Memory Usage: 9.3 MB, less than 100.00% of C++ online submissions for Check If N and Its Double Exist.
// time complexity: O(n)
// space complexity: O(n)