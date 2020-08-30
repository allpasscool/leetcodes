class Solution {
public:
    Solution(vector<int>& w) {
        aggregated_sum = vector<int> (w.size());
        
        for (int i = 0; i < w.size(); ++i) {
            sum += w[i];
            aggregated_sum[i] = sum;
        }
    }
    
    int pickIndex() {        
        int random = rand() % sum + 1;
        int ans = binarySearch(random, 0, aggregated_sum.size() - 1);
        return ans;
    }
private:
    int sum = 0;
    vector<int> aggregated_sum;
    
    int binarySearch(int random, int left, int right) {
        
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            // get answer
            if (random == aggregated_sum[mid]) {
                return mid;
            }
            
            // left side
            else if (random < aggregated_sum[mid]) {
                right = mid;
            }
            
            // right side
            else if (random > aggregated_sum[mid]) {
                left = mid + 1;
            }
        }
        
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

// Runtime: 332 ms, faster than 21.28% of C++ online submissions for Random Pick with Weight.
// Memory Usage: 40.1 MB, less than 95.41% of C++ online submissions for Random Pick with Weight.
// time complexity: Solution O(n) pickIndex O(log n)
// space copmlexity: O(n)