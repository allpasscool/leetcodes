class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto ticket : tickets) {
            targets[ticket[0]].insert(ticket[1]);
        }
        
        visit("JFK");
        return vector<string> (route.rbegin(), route.rend());
    }
    
private:
    void visit(string airport) {
        while (targets[airport].size()) {
            string next = *targets[airport].begin();
            targets[airport].erase(targets[airport].begin());
            visit(next);
        }
        
        route.push_back(airport);
    }
    
    map<string, multiset<string>> targets;
    vector<string> route;
};


// Runtime: 24 ms, faster than 83.20% of C++ online submissions for Reconstruct Itinerary.
// Memory Usage: 17.5 MB, less than 25.00% of C++ online submissions for Reconstruct Itinerary.
// time complexity: O(n)
// space complexity: O(n)
// https://leetcode.com/problems/reconstruct-itinerary/discuss/78768/Short-Ruby-Python-Java-C%2B%2B

// class Solution {
// public:
//     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         for (auto ticket : tickets)
//             targets[ticket[0]].insert(ticket[1]);
//         visit("JFK");
//         return vector<string>(route.rbegin(), route.rend());
//     }

//     map<string, multiset<string>> targets;
//     vector<string> route;

//     void visit(string airport) {
//         while (targets[airport].size()) {
//             string next = *targets[airport].begin();
//             targets[airport].erase(targets[airport].begin());
//             visit(next);
//         }
//         route.push_back(airport);
//     }
// };