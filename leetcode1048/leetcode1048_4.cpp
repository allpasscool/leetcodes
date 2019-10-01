class Solution {
public:
    int longestStrChain(vector<string>& words) {
        int output = 0;
        
        unordered_map<int, vector<string>> nodes; // push all same length words into the same vector
        
        for (auto w: words) {
            nodes[w.length()].push_back(w);
        }
        
        unordered_map<string, int> memo;
        
        for (auto it = nodes.begin(); it != nodes.end(); ++it) {
            auto & seeds = it->second;
            
            for (auto& s: seeds) {
                output = max(output, dfs(s, nodes, memo));
            }
        }
        
        return output;
    }
    
private:
    bool isPredecessor(const string& s1, const string& s2) {
        if (s2.length() != s1.length() + 1)
            return false;
        
        int s1_counter = 0, s2_counter = 0;
        int diff = 0;
        
        while (s1_counter < s1.length() && s2_counter < s2.length()) {
            if (s1[s1_counter] == s2[s2_counter]) {
                ++s1_counter;
                ++s2_counter;
            }
            else {
                ++s2_counter;
                ++diff;
                
                if (diff > 1)
                    return false;
            }
        }
        
        return true;
    }
    
    int dfs(const string& w, unordered_map<int, vector<string>>& nodes,
           unordered_map<string, int>& memo) {
        if (memo[w] != 0)
            return memo[w];
        
        int output = 1;
        
        // no word with w.length() + 1
        if (nodes.find(w.length() + 1) == nodes.end())
            return output;
        
        auto& candidates = nodes[w.length() + 1];
        for(const auto& c: candidates) {
            if (isPredecessor(w, c))
                output = max(output, dfs(c, nodes, memo) + 1);
        }
        
        memo[w] = output;
        return output;
    }
};

// Runtime: 36 ms, faster than 97.54% of C++ online submissions for Longest String Chain.
// Memory Usage: 19.6 MB, less than 100.00% of C++ online submissions for Longest String Chain.
// time complexity: O(n), n is # of words
// space complexity: O(n)


// bool isConnected(const string& w1, const string& w2)
//     {   
//         if (w1.size()+1 != w2.size()) return false;

//         int i=0, j=0;
//         while(i<w1.size() && j<w2.size())
//         {
//             if (w1[i++]!=w2[j++])
//             {
//                 i--; 
//                 if (j-i>1)
//                     return false;
//             }     
//         }

//         return true;
//     }


//     int dfs(const string& w, unordered_map<int, vector<string>>& nodes, 
//             unordered_map<string, int>& memo){

//         if (memo.count(w))
//             return memo.at(w);

//         int result = 1;

//         if (!nodes.count(w.size()+1))
//             return result;

//         auto& candidates = nodes[w.size()+1];
//         for (const auto& c : candidates)
//         {
//             if (isConnected(w, c))
//             {
//                 result = max(result, dfs(c, nodes, memo)+1);
//             }
//         }

//         memo[w] = result;
//         return result;
//     }

//     int longestStrChain(vector<string>& words) {

//         int result = 0;
//         unordered_map<string, int> memo;
//         unordered_map<int, vector<string>> nodes;
//         for (const auto& w : words)
//         {
//             nodes[w.size()].emplace_back(w);
//         }

//         for (auto it = nodes.begin(); it != nodes.end(); it++)
//         {
//             auto & seeds = it->second;
//             for (auto & s : seeds)
//             {
//                 result = max(dfs(s, nodes, memo), result);
//             }
//         }

//         return result;        
//     }