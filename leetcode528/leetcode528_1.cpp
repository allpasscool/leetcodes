class Solution {
public:
    Solution(vector<int>& w) {
        aggregated_sum = vector<int> (w.size());
        int sum = 0;
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            aggregated_sum[i] = sum;
        }
    }
    
    int pickIndex() {        
        int random = rand() % aggregated_sum.back();
        
        return upper_bound(begin(aggregated_sum), end(aggregated_sum), random) - begin(aggregated_sum);
    }
private:
    vector<int> aggregated_sum;
};

// Runtime: 380 ms, faster than 16.64% of C++ online submissions for Random Pick with Weight.
// Memory Usage: 40.4 MB, less than 55.60% of C++ online submissions for Random Pick with Weight.
// time complexity: Solution O(n) pickIndex O(log n)
// space copmlexity: O(n)