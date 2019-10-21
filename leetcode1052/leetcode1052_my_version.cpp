class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int base = 0;
        int n = customers.size();
        
        // base
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) {
                base += customers[i];
            }
        }
        
        // test all X
        int max_save = 0;
        for (int i = 0; i < n; ++i) {
            // cout << i << endl;
            // only start from grumpy minute
            if (grumpy[i] == 1) {
                int tmp = 0;
                for (int j = 0; j < X && i + j < n; ++j) {
                    
                    if (grumpy[i + j] == 1)
                        tmp += customers[i + j];
                }
                max_save = max(max_save, tmp);
            }
        }
        
        return base + max_save;
    }
};


// Runtime: 1112 ms, faster than 5.03% of C++ online submissions for Grumpy Bookstore Owner.
// Memory Usage: 11.3 MB, less than 100.00% of C++ online submissions for Grumpy Bookstore Owner.
// time complexity: O(n * X)
// space complexity: O(1)