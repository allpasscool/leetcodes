class Solution {
public:
    int threeSumMulti(vector<int>& A, int target) {
        const int n = A.size();
        const int max_a = 100;
        const int mod = 1e9 + 7;
        vector<long> fre(max_a + 1, 0);
        
        for (auto num : A)
            ++fre[num];
        
        long ans = 0;
        
        // i + j + k == target
        for (int i = 0; i <= target / 3; ++i) {
            for (int j = i; j <= target / 2; ++j) {
                const int k = target - i - j;
                
                // k is too small or too big
                if (k < 0 || k > max_a || k < j)
                    continue;
                // no i or j or k
                if (fre[i] == 0 || fre[j] == 0 || fre[k] == 0)
                    continue;
                
                // case 1: i == j == k
                // C(n, 3) = n 8 (n - 1) * (n - 2) / 6
                if (i == j && j == k)
                    ans += fre[i] * (fre[i] - 1) * (fre[i] - 2) / 6;
                // case 2: i == j != k
                // C(n, 2) * fre[k] = n * (n - 1) / 2 * fre[k];
                else if (i == j && j != k) 
                    ans += fre[i] * (fre[i] - 1) / 2 * fre[k];
                // case 3: i != j == k
                // fre[i] * C(n, 2) = fre[i] * n * (n - 1) / 2
                else if (i != j && j == k)
                    ans += fre[i] * fre[j] * (fre[j] - 1) / 2;
                // case 4 : i != j != k
                else 
                    ans += fre[i] * fre[j] * fre[k];
            }
        }
        
        return ans % mod;
    }
};


// Runtime: 4 ms, faster than 99.84% of C++ online submissions for 3Sum With Multiplicity.
// Memory Usage: 9 MB, less than 100.00% of C++ online submissions for 3Sum With Multiplicity.
// time complexity: O(n + target^2)
// space complexity: O(target)

// Author: Huahua, runtime: 4 ms
// class Solution {
// public:
//   int threeSumMulti(vector<int>& A, int target) {    
//     constexpr int kMaxN = 100;
//     constexpr int kMod = 1e9 + 7;
//     vector<long> c(kMaxN + 1, 0);
//     for (int a : A) ++c[a];
//     long ans = 0;
//     for (int i = 0; i <= target; ++i) {
//       for (int j = i; j <= target; ++j) {
//         const int k = target - i - j;
//         if (k < 0 || k >= c.size() || k < j) continue;
//         if (!c[i] || !c[j] || !c[k]) continue;
//         if (i == j && j == k)
//           ans += (c[i] - 2) * (c[i] - 1) * c[i] / 6;
//         else if (i == j && j != k)
//           ans += c[i] * (c[i] - 1) / 2 * c[k];
//         else if (i != j && j == k)
//           ans += c[i] * (c[j] - 1) * c[j] / 2;
//         else
//           ans += c[i] * c[j] * c[k];        
//       }
//     }
//     return ans % kMod;
//   }
// };
// https://zxi.mytechroad.com/blog/hashtable/leetcode-923-3sum-with-multiplicity/