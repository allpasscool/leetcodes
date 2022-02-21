class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int lowBuy = prices[0];
        int profit = 0;

        for (int price : prices)
        {
            profit = max(profit, price - lowBuy);
            lowBuy = min(lowBuy, price);
        }

        return profit;
    }
};

// Runtime: 188 ms, faster than 46.93% of C++ online submissions for Best Time to Buy and Sell Stock.
// Memory Usage: 93.4 MB, less than 53.84% of C++ online submissions for Best Time to Buy and Sell Stock.
// time complexity: O(n)
// space complexity: O(1)