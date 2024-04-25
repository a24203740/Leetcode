/*
 * @lc app=leetcode id=310 lang=cpp
 *
 * [310] Minimum Height Trees
 */

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        if(n == 1)
        {
            ans.push_back(0);
            return ans;
        }
        vector<vector<int>> adjList(n, vector<int>());
        vector<int> deg(n, 0);
        for(auto &e : edges)
        {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
            deg[e[0]]++;
            deg[e[1]]++;
        }
        queue<int> leaf;
        int leafCount = 0;
        for(int i = 0; i < n; i++)
        {
            if(deg[i] == 1)
            {
                leaf.push(i);
                leafCount++;
            }
        }
        while(!leaf.empty())
        {
            if(leafCount == n)
            {
                ans.clear();
                while(!leaf.empty())
                {
                    ans.push_back(leaf.front());
                    leaf.pop();
                }
                return ans;
            }
            int sz = leaf.size();
            while(sz--)
            {
                int f = leaf.front();
                leaf.pop();
                for(auto x : adjList[f])
                {
                    deg[x]--;
                    if(deg[x] == 1)
                    {
                        leaf.push(x);
                        leafCount++;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

