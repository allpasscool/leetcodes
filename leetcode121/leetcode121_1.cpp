class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
            }
            
            if (prices[i] - buy > profit) {
                profit = prices[i] - buy;
            }
        }
        
        return profit;
    }
};
// Runtime: 4 ms, faster than 98.41% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.6 MB, less than 66.06% of C++ online submissions for Best Time to Buy and Sell Stock.
// time complexity: O(n)
// space complexity: O(1)