class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(), A.end());
        
        int left = 0, right = A.size() - 1;
        int ans = 0;
        
        while (left != right) {
            int sum = A[left] + A[right];
            
            if (sum > K) {
                right--;
            }
            else if (sum < K) { 
                ans = max(ans, sum);
                ++left;
            }
            else if (sum == K) {
                right--; // keep finding smaller than K
            }
        }
        
        return ans == 0 ? -1 : ans;
    }
};

// Runtime: 4 ms, faster than 87.00% of C++ online submissions for Two Sum Less Than K.
// Memory Usage: 8.5 MB, less than 50.00% of C++ online submissions for Two Sum Less Than K.
// time complexity: O(n log n)
// space complexity: O(1)