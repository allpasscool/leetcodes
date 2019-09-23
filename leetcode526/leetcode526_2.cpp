class Solution {
public:
    int countArrangement(int N) {
        vector<bool> visited (N + 1, false);
        calculate(N, 1, visited);
        
        return count;
    }
    
    void calculate(int& N, int pos, vector<bool>& visited) {
        if (pos > N)
            ++count;
        
        for (int i = 1; i <= N; ++i) {
            if (!visited[i] && (pos % i == 0 || i % pos == 0)) {
                visited[i] = true;
                calculate(N, pos + 1, visited);
                visited[i] = false;
            }
        }
    }
    
private:
    int count = 0;
};

// Runtime: 220 ms, faster than 26.93% of C++ online submissions for Beautiful Arrangement.
// Memory Usage: 8.1 MB, less than 100.00% of C++ online submissions for Beautiful Arrangement.
// time complexity: O(N^N)
// space complexity: O(n)