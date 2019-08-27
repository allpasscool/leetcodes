class Solution {
public:
    vector<string> invalidTransactions(vector<string>& transactions) {
        unordered_set<string> output;
        int n = transactions.size();
        unordered_map<string, vector<pair<string, int>>> name_and_city_and_time;
        vector<string> name_a, city_a;
        vector<int> time_a, amount_a;
        
        for (int i = 0; i < n; i++) {
            string trans = transactions[i];
            string name = "";
            int j = 0;
            while (trans[j] != ',') {
                name += trans[j];
                j++;
            }
            name_a.push_back(name);
            
            string time = "";
            j++;
            while (trans[j] != ',') {
                time += trans[j];
                j++;
            }
            
            int time_n = 0;
            for (int k = 0; k < time.length(); k++) {
                time_n *= 10;
                time_n += (int)(time[k] - '0');
            }
            time_a.push_back(time_n);
            
            string amount = "";
            j++;
            while (trans[j] != ',') {
                amount += trans[j];
                j++;
            }
            int amount_n = 0;
            for (int k = 0; k < amount.length(); k++) {
                amount_n *= 10;
                amount_n += (int)(amount[k] - '0');
            }
            amount_a.push_back(amount_n);
            
            string city = "";
            j++;
            while (j < trans.length()) {
                city += trans[j];
                j++;
            }
            city_a.push_back(city);
        }
        
        for (int i = 0; i < n; i++) {
            if (amount_a[i] > 1000) {
                output.insert(transactions[i]);
            }
            for (int j = i + 1; j < n; j++) {
                if (name_a[i] == name_a[j] && city_a[i] != city_a[j] && abs(time_a[i] - time_a[j]) <= 60) {
                    output.insert(transactions[i]);
                    output.insert(transactions[j]);
                }
            }
            
        }
        
        vector<string> o;
        for(auto s: output) {
            o.push_back(s);
        }
        
        return o;
        
    }
};
// Runtime: 60 ms, faster than 55.45% of C++ online submissions for Invalid Transactions.
// Memory Usage: 16.6 MB, less than 100.00% of C++ online submissions for Invalid Transactions.
// time complexity: O(n)
// space complexity: O(n)