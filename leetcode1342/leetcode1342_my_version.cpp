class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> hashmap;
        
        for (auto n : arr) {
            ++hashmap[n];
        }
        
        priority_queue<int> pq;
        
        for (auto p : hashmap) {
            pq.push(p.second);
        }
        
        int count = 0;
        int ans = 0;
        
        while (count < arr.size() / 2) {
            count += pq.top();
            ++ans;
            pq.pop();
            
        }
        
        
        return ans;
    }
};


// Runtime: 236 ms, faster than 100.00% of C++ online submissions for Reduce Array Size to The Half.
// Memory Usage: 38.3 MB, less than 100.00% of C++ online submissions for Reduce Array Size to The Half.
// time complexity: O(n log n)
// space complexity: O(n)