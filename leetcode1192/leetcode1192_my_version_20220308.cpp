class Solution
{
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
    {

        for (auto connection : connections)
        {
            graph[connection[0]].push_back(connection[1]);
            graph[connection[1]].push_back(connection[0]);
        }

        dfs(0, -1);

        return ans;
    }

private:
    struct Vertex
    {
        int label;
        int lowLink;
    };
    unordered_map<int, vector<int>> graph;
    unordered_map<int, struct Vertex> nodeTime;
    int timestamp = 0;
    vector<vector<int>> ans;

    int dfs(int node, int from)
    {
        if (nodeTime.find(node) != nodeTime.end())
            return nodeTime[node].lowLink;

        nodeTime[node] = Vertex{timestamp, timestamp};
        timestamp++;

        for (int n : graph[node])
        {
            if (n == from)
                continue;

            int nLow = dfs(n, node);
            nodeTime[node].lowLink = min(nodeTime[node].lowLink, nLow);

            if (nLow > nodeTime[node].label)
                ans.push_back({node, n});
        }

        return nodeTime[node].lowLink;
    }
};

// Runtime: 1376 ms, faster than 11.88% of C++ online submissions for Critical Connections in a Network.
// Memory Usage: 228.1 MB, less than 6.96% of C++ online submissions for Critical Connections in a Network.
// time complexity: O(n)
// space complexity: O(n)