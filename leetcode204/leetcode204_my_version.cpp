class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        
        if (n <= 2) {
            return 0;
        }
        
        primes[0] = false;
        primes[1] = false;
        primes[2] = true;
        
        // disable non prime number
        for (int i = 2; i < n; ++i) {
            // i is not a prime
            if (!primes[i]) {
                continue;
            }
            
            for (int j = i; (long long)i * j < n; ++j) {
                primes[i * j] = false;
            }
        }
        
        int count = 0;
        
        for (int i = 2; i < n; ++i) {
            count += primes[i] ? 1 : 0;
        }
        
        return count;
    }
};


// Runtime: 84 ms, faster than 41.12% of C++ online submissions for Count Primes.
// Memory Usage: 8.8 MB, less than 41.67% of C++ online submissions for Count Primes.
// time complexity: O(n^2)
// space complexity: O(n)