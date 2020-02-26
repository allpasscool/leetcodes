class Solution {
public:
    bool isPossible(vector<int>& target) {
        long total = 0;
        int n = target.size(), num;
        priority_queue<int> pq(begin(target), end(target));
        
        for (auto num : target)
            total += num;
        
        while (true) {
            num = pq.top();
            pq.pop();
            
            total -= num;
            
            if (num == 1 || total == 1)
                return true;
            
            if (num < total || total == 0 || num % total == 0)
                return false;
            
            num %= total;
            total += num;
            
            pq.push(num);
        }
    }
};

// https://leetcode.com/problems/construct-target-array-with-multiple-sums/discuss/510256/JavaC%2B%2BPython-Backtrack-OJ-is-wrong
// Runtime: 60 ms, faster than 88.20% of C++ online submissions for Construct Target Array With Multiple Sums.
// Memory Usage: 13.8 MB, less than 100.00% of C++ online submissions for Construct Target Array With Multiple Sums.
// time complexity: O(log max_Num * log n)
// space complexity: O(n)

// bool isPossible(vector<int>& A) {
//     long total = 0;
//     int n = A.size(), a;
//     priority_queue<int> pq(A.begin(), A.end());
//     for (int a : A)
//         total += a;
//     while (true) {
//         a = pq.top(); pq.pop();
//         total -= a;
//         if (a == 1 || total == 1)
//             return true;
//         if (a < total || total == 0 || a % total == 0)
//             return false;
//         a %= total;
//         total += a;
//         pq.push(a);
//     }
// }

