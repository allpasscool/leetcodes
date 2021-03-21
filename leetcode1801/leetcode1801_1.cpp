class Solution {
public:
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        priority_queue<vector<int>> buy;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> sell;
        
        for (auto& o: orders) {
            if (o[2] == 0)
                buy.push(o);
            else
                sell.push(o);
            
            while (buy.size() 
                   && sell.size() 
                   && sell.top()[0] <= buy.top()[0]) {
                
                int n = min(buy.top()[1], sell.top()[1]);
                
                // buy
                vector<int> tmp = buy.top();
                buy.pop();
                tmp[1] -= n;
                if (tmp[1]) buy.push(tmp);
                
                // sell
                tmp = sell.top(); sell.pop();
                tmp[1] -= n;
                if (tmp[1])
                    sell.push(tmp);
            }
        }
        
        int res = 0, mod = 1e9 + 7;
        
        while (sell.size()) {
            res = (res + sell.top()[1]) % mod;
            sell.pop();
        }
        
        while (buy.size()) {
            res = (res + buy.top()[1]) % mod;
            buy.pop();
        }
        
        return res;
    }
};

// Runtime: 608 ms, faster than 100.00% of C++ online submissions for Number of Orders in the Backlog.
// Memory Usage: 74 MB, less than 100.00% of C++ online submissions for Number of Orders in the Backlog.
// time complexity: O(n logn)
// space complexity: O(n)
// https://leetcode.com/problems/number-of-orders-in-the-backlog/discuss/1119992/JavaC%2B%2BPython-Priority-Queue

// int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
//     priority_queue<vector<int>>buy;
//     priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>sell;
//     for (auto& o : orders) {
//         if (o[2] == 0)
//             buy.push(o);
//         else
//             sell.push(o);
//         while (buy.size() && sell.size() && sell.top()[0] <= buy.top()[0]) {
//             int k = min(buy.top()[1], sell.top()[1]);
//             vector<int> tmp = buy.top(); buy.pop();
//             tmp[1] -= k;
//             if (tmp[1]) buy.push(tmp);

//             tmp = sell.top(); sell.pop();
//             tmp[1] -= k;
//             if (tmp[1]) sell.push(tmp);
//         }

//     }
//     int res = 0, mod = 1e9 + 7;
//     while (sell.size())
//         res = (res + sell.top()[1]) % mod, sell.pop();
//     while (buy.size())
//         res = (res + buy.top()[1]) % mod, buy.pop();
//     return res;
// }