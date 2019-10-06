class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int cost = 0;
        
        // destination is odd or even
        for (int i = 0; i < 2; ++i) {
            int tmp = 0;
            // chips j
            for (int j = 0; j < chips.size(); ++j) {
                tmp += (chips[j] - i) % 2;
            }
            
            if (i == 0)
                cost = tmp;
            else 
                cost = min(cost, tmp);
        }
        
        return cost;
    }
};

// Runtime: 4 ms, faster than 80.00% of C++ online submissions for Play with Chips.
// Memory Usage: 8.5 MB, less than 100.00% of C++ online submissions for Play with Chips.
// time complexity: O(n)
// space complexity: O(1)