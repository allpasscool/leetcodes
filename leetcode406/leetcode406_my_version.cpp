class Solution {
private:
    static bool comp(vector<int>& n1, vector<int>& n2) {
        return n1[0] > n2[0] || (n1[0] == n2[0] && n1[1] < n2[1]);
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        if (people.size() == 0) {
            return vector<vector<int>> {};
        }
        
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> output;
        
        output.push_back(people[0]);
        
        for (int i = 1; i < people.size(); i++) {
            int j = people[i][1];
            output.insert(output.begin() + j, people[i]);
        }
        
        return output;
    }
};
// Runtime: 80 ms, faster than 70.60% of C++ online submissions for Queue Reconstruction by Height.
// Memory Usage: 12.5 MB, less than 61.90% of C++ online submissions for Queue Reconstruction by Height.
// time complexity: O(n^2), n logn sort and for each n take n time to insert, n^2
// space complexity: O(n)