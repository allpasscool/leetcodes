class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] > prices[i - 1]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        
        return profit;
    }
};
// Runtime: 8 ms, faster than 60.62% of C++ online submissions for Best Time to Buy and Sell Stock II.
// Memory Usage: 9.5 MB, less than 93.65% of C++ online submissions for Best Time to Buy and Sell Stock II.
// time complexity: O(n)
// space complexity: O(1)