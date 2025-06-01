#include "../includes.hpp"

using adjmat = vector<vector<int>>;
class Solution {
public:
  void DFS(int cur, int par, int depth, const adjmat &adj,
           vector<int> &depths) {
    depths[cur] = depth;
    for (int next : adj[cur]) {
      if (next != par) {
        DFS(next, cur, depth + 1, adj, depths);
      }
    }
  }
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    int maxDepth1 = 0, maxDepth2 = 0;
    int n1 = edges1.size() + 1;
    int n2 = edges2.size() + 1;
    adjmat adj1(n1), adj2(n2);
    vector<int> depths1(n1, 0), depths2(n2, 0);
    for (auto &e : edges1) {
      adj1[e[0]].push_back(e[1]);
      adj1[e[1]].push_back(e[0]);
    }
    for (auto &e : edges2) {
      adj2[e[0]].push_back(e[1]);
      adj2[e[1]].push_back(e[0]);
    }
    DFS(0, -1, 0, adj1, depths1);
    DFS(0, -1, 0, adj2, depths2);
    int oddConut1 = 0, evenCount1 = 0;
    int oddConut2 = 0, evenCount2 = 0;
    for(int i = 0; i < n1; i++) {
      if(depths1[i] % 2 == 0) {
        evenCount1++;
      } else {
        oddConut1++;
      }
    }
    for(int i = 0; i < n2; i++) {
      if(depths2[i] % 2 == 0) {
        evenCount2++;
      } else {
        oddConut2++;
      }
    }
    int bouns = max(oddConut2, evenCount2);
    vector<int> ans(n1);
    for(int i = 0; i < n1; i++) {
      int d = depths1[i];
      if(d % 2 == 0) {
        ans[i] = evenCount1 + bouns;
      }
      else ans[i] = oddConut1 + bouns;
    }
    return ans;
  }
};
