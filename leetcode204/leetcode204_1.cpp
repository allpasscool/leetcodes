class Solution {
public:
    int countPrimes(int n) {
        vector<bool> primes(n, true);
        
        if (n <= 2) {
            return 0;
        }
        
        int count = 0;
        
        primes[0] = false;
        primes[1] = false;
        primes[2] = true;
        ++count;
        
        
        // disable non prime number
        for (int i = 3; i < n; i += 2) {
            // i is not a prime
            if (!primes[i]) {
                continue;
            }
            
            ++count;
            for (int j = i; (long long)i * j < n; ++j) {
                primes[i * j] = false;
            }
        }
        
        return count;
    }
};


// Runtime: 44 ms, faster than 71.89% of C++ online submissions for Count Primes.
// Memory Usage: 8.8 MB, less than 50.00% of C++ online submissions for Count Primes.
// time complexity: O(n^2)
// space complexity: O(n)
// https://leetcode.com/problems/count-primes/discuss/57594/My-easy-one-round-c%2B%2B-code