class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int tmp = 0;
        int n = customers.size();
        int max_customers = 0;
        int max_grumpy = 0;
        int base = 0;
        queue<int> grumpy_index;
        
        int left = 0, right = 0;
        
        for (int i = 0; i < n; ++i) {
            if (i - left >= X) {
                if (grumpy[left] == 1)
                    tmp -= customers[left];
                
                ++left;
            }
            
            if (grumpy[i] == 0)
                base += customers[i];
            // grumpy == 1
            else {
                tmp += customers[i];
                
                max_grumpy = max(max_grumpy, tmp);
            }
            
            
        }
        
        max_customers = base + max_grumpy;
        
        return max_customers;
    }
};

// Runtime: 36 ms, faster than 92.69% of C++ online submissions for Grumpy Bookstore Owner.
// Memory Usage: 11.5 MB, less than 100.00% of C++ online submissions for Grumpy Bookstore Owner.
// time complexity: O(n)
// space complexity: O(1)