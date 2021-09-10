class Solution {
public:
    int confusingNumberII(int n) {
        rotate[0] = 0;
        rotate[1] = 1;
        rotate[6] = 9;
        rotate[8] = 8;
        rotate[9] = 6;
        
        int cur = 0;
        findConfusing(n, cur);
        
        return ans;
    }
    
private:
    unordered_map<int, int> rotate;
    int ans = 0;
    
    void findConfusing(long long n, long long cur)
    {
        if (match(cur))
            ans++;
        
        for (auto p : rotate)
        {
            if (cur * 10 + p.first <= n && cur * 10 + p.first > 0)
            {
                findConfusing(n, cur * 10 + p.first);
            }
        }
    }
    
    bool match(long long n)
    {
        long long origin = n;
        int cur = 0;
        
        while (n > 0)
        {
            int remainder = n % 10;
            cur = cur * 10 + rotate[remainder];
            n /= 10;
        }
        
        return origin != cur;
    }
};

// Runtime: 1080 ms, faster than 18.68% of C++ online submissions for Confusing Number II.
// Memory Usage: 6.1 MB, less than 34.34% of C++ online submissions for Confusing Number II.
// time complexity: O(5^(logn))
// space complexity: O(1)

// https://leetcode.com/problems/confusing-number-ii/discuss/446589/Easy-to-understand-Java-backtracking-solution-covers-edge-case
// class Solution {
//     Map<Integer, Integer> map = new HashMap<>();
//     int res = 0;
//     public int confusingNumberII(int N) {
//         map.put(0, 0);
//         map.put(1, 1);
//         map.put(6, 9);
//         map.put(8, 8);
//         map.put(9, 6);
//         helper(N, 0);
//         return res;
//     }
//     private void helper(int N, long cur) {
//         if (isConfusingNumber(cur)) {
//             res++;
//         }
//         for (Integer i : map.keySet()) {
//             if (cur * 10 + i <= N && cur * 10 + i != 0) {
//                 helper(N, cur * 10 + i);
//             }
//         }
//     }
//     private boolean isConfusingNumber(long n) {
//         long src = n;
//         long res = 0;
//         while (n > 0) {
//             res = res * 10 + map.get((int) n % 10); 
//             n /= 10;
//         }
//         return res != src;
//     }
// }