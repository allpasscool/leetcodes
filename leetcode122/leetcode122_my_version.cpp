class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 0) {
            return 0;
        }
        
        int profit = 0, buy = prices[0], sell = prices[0];
        
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < sell) {
                profit += sell - buy;
                buy = prices[i];
                sell = prices[i];
            }
            else if (prices[i] > sell) {
                sell = prices[i];
            }
        }
        
        if (sell > buy) {
            profit += sell - buy;
        }
        
        return profit;
    }
};
// Runtime: 4 ms, faster than 98.06% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 9.5 MB, less than 100.00% of C++ online submissions for Best Time to Buy and Sell Stock II.
// time complexity: O(n)
// space complexity: O(1)