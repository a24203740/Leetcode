/*
 * @lc app=leetcode id=1971 lang=cpp
 *
 * [1971] Find if Path Exists in Graph
 */

// @lc code=start
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int dest) {
        vector<vector<int>> adj(n);
        for(auto &v : edges)
        {
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> visit(n, false);
        queue<int> bfs;
        bfs.push(source);
        visit[source] = true;
        while(!bfs.empty())
        {
            int next = bfs.front();
            bfs.pop();
            for(auto x : adj[next])
            {
                if(!visit[x])
                {
                    if(x == dest)return true;
                    visit[x] = true;
                    bfs.push(x);
                }
            }
        }
        if(visit[dest])return true;
        return false;
    }
};
// @lc code=end

