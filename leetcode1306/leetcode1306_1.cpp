class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 && start < arr.size() 
            && (visited.find(start) == visited.end()) ) {
            visited.insert(start);
            
            return arr[start] == 0 
                || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }
        
        return false;
    }
private:
    unordered_set<int> visited;
};


// Runtime: 64 ms, faster than 13.34% of C++ online submissions for Jump Game III.
// Memory Usage: 12.9 MB, less than 100.00% of C++ online submissions for Jump Game III.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/jump-game-iii/discuss/464083/C%2B%2BJava-Recursion