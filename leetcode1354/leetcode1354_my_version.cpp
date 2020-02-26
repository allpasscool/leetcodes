class Solution {
public:
    bool isPossible(vector<int>& target) {
        if (target.size() == 1) {
            return target[0] == 1;
        } 
        else if (target.size() == 0) {
            return false;
        }
        
        int n = target.size();
        long long sum = 0;
        priority_queue<long long> pq;
        
        for (auto n : target) {
            sum += n;
            pq.push(n);
        }
        
        // max_num > sum / 2
        if (pq.top() < sum / 2) {
            return false;
        }
        
        // all 1s
        if (pq.top() == 1) {
            return true;
        }
        // max_num is invalid
        else if (pq.top() > 1 && pq.top() < n) {
            return false;
        }
        
        while (!pq.empty()) {
            long long max_num = pq.top();
            pq.pop();
            sum -= max_num;
            // max_num = 1 + k * (n - 1)
            if (sum == n - 1 && (max_num - 1) % sum == 0) {
                return true;
            }
            
            if (sum >= max_num) {
                return false;
            }
            cout << sum << endl;
            max_num %= sum;
            
            if (max_num > 1 && max_num < n) {
                return false;
            }
            else if (max_num < 1) {
                return false;
            }
            
            sum += max_num;
            if (max_num != 1) {
                pq.push(max_num);
            }
        }
        return false;
    }
};


// Runtime: 68 ms, faster than 51.38% of C++ online submissions for Construct Target Array With Multiple Sums.
// Memory Usage: 17.8 MB, less than 100.00% of C++ online submissions for Construct Target Array With Multiple Sums.
// time complexity: O(n)
// space complexity: O(1)