class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = INT_MAX, sell = 0, profit = 0;
        
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < buy) {
                buy = prices[i];
                sell = 0;
            } else if (prices[i] > sell) {
                sell = prices[i];
            }
            
            if (sell - buy > profit) {
                profit = sell - buy;
            }
        }
        
        return profit;
    }
};
// Runtime: 4 ms, faster than 98.41% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 9.4 MB, less than 99.08% of C++ online submissions for Best Time to Buy and Sell Stock.
// time complexity: O(n)
// space complexity: O(1)