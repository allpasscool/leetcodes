class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<int> buy;
        unordered_map<int, int> buy_map, sell_map;
        priority_queue<int, vector<int>, greater<int>> sell;
        const int MOD = 1000000007;
        long long ans = 0;
        
        for (int i = 0; i < orders.size(); ++i) {
            // buy
            if (orders[i][2] == 0) {
                int price = orders[i][0];
                int count = orders[i][1];
                
                // match
                if (sell.size() > 0 && sell.top() <= price) {
                    while (count > 0 && sell.size() > 0 && sell.top() <= price) {
                        int sell_price = sell.top();
                        int num = min(count, sell_map[sell_price]);
                        count -= num;
                        sell_map[sell_price] -= num;
                        ans -= num;
                        
                        if (sell_map[sell_price] == 0)
                            sell.pop();
                    }
                }
                
                // add to backlog
                if(count > 0) {
                    if (buy_map[price] == 0)
                        buy.push(price);
                    
                    buy_map[price] += count;
                    ans += count;
                }
            }
            // sell
            else {
                int price = orders[i][0];
                int count = orders[i][1];
                
                // match
                if (buy.size() > 0 && buy.top() >= price) {
                    while (count > 0 && buy.size() > 0 && buy.top() >= price) {
                        int num = min(count, buy_map[buy.top()]);
                        count -= num;
                        buy_map[buy.top()] -= num;
                        ans -= num;
                        
                        if (buy_map[buy.top()] == 0)
                            buy.pop();
                    }
                }
                
                // add to backlog
                if(count > 0) {
                    if (sell_map[price] == 0)
                        sell.push(price);
                    
                    sell_map[price] += count;
                    ans += count;
                }
            }
        }
        
        return ans % MOD;
    }
};

// Runtime: 220 ms, faster than 100.00% of C++ online submissions for Number of Orders in the Backlog.
// Memory Usage: 63.9 MB, less than 100.00% of C++ online submissions for Number of Orders in the Backlog.
// time complexity: O(n log n)
// space complexity: O(n)