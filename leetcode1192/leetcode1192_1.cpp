class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        check.resize(n);
        
        // construct graph
        for (auto &edge : connections) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }
        
        // for (int i = 0; i < n; ++i) {
        //     if (check[i].index == 0) { // not visited
        //         dfs(i, -1);
        //     }
        // }
        
        dfs(0, -1); // start from node 0
        
        return ans;
    }
private:
    void dfs (int v, int parent) {
        check[v].index = time_stamp;
        check[v].low_link = time_stamp;
        ++time_stamp;
        
        for (auto &w : graph[v]) {
            if (w == parent)
                continue;
            if (check[w].index == 0) { // not visited
                dfs(w, v);
                
                // calculate the earlist point that can be reached by a non-father node
                check[v].low_link = min(check[v].low_link, check[w].low_link);
                if (check[w].low_link > check[v].index) { // this must be a bridge
                    ans.push_back({v, w});
                }
            }
            else {
                check[v].low_link = min(check[v].low_link, check[w].index);
            }
        }
    }
    map<int, vector<int>> graph;
    int time_stamp = 1;
    struct Vetex {
        int index; // time_stamp
        int low_link; // the earliest point int can be reached by a non-father node
    };
    vector<Vetex> check;
    vector<vector<int>> ans;
};

// Runtime: 1032 ms, faster than 16.03% of C++ online submissions for Critical Connections in a Network.
// Memory Usage: 172.6 MB, less than 100.00% of C++ online submissions for Critical Connections in a Network.
// time complexity: O(n)
// space complexity: O(|E| + |N|)
// https://leetcode.com/problems/critical-connections-in-a-network/discuss/382515/readable-C%2B%2B-code

// class Solution {
// 	public:
// 		map< int ,vector< int > > graph ;
// 		int time_stamp = 1 ;  
// 		struct Vetex {
// 			int index ;  // time_stamp 
// 			int lowlink ; // The earliest point that can be reached by a non-father node
// 		};
// 		vector< Vetex > check ;
// 		vector< vector<int> > ans ; 
// 		void dfs( int v , int parent ) {

// 			check[v].index = time_stamp ; 
// 			check[v].lowlink = time_stamp ;
// 			time_stamp ++ ;

// 			for( auto &w : graph[v] ){
// 				if ( w == parent ) continue ; 
// 				if ( check[w].index == 0 ){ // not visited
// 					dfs( w , v ) ; 
// 					// calc The earliest point that can be reached by a non-father node
// 					check[v].lowlink = min( check[v].lowlink , check[w].lowlink ) ; 
// 					if ( check[w].lowlink > check[v].index ) // this must be a bridge 
// 						ans.push_back( {v,w } ) ; 
// 				}  else {
// 					check[v].lowlink = min( check[v].lowlink , check[w].index ) ; 
// 				}
// 			}

// 		}
// 		vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
// 			check.resize( n+1 ) ; 
// 			// construct graph 
// 			for( auto &edge : connections ) {
// 				graph[edge[0]].push_back( edge[1] ) ; 
// 				graph[edge[1]].push_back( edge[0] ) ; 
// 			}
// 			for( int i=0 ; i< n ; i++ ) 
// 				if ( check[i].index == 0 ) // not visited 
// 					dfs( i , -1 ) ; 
// 			return ans ; 
// 		}
// 	};

//  biggest testcase
// 100000