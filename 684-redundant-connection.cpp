#include "includes.hpp"

class Solution {
public:
  vector<int> par;
  void init(int n) {
    par.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      par[i] = i;
    }
  }
  int find(int x) {
    if (par[x] == x)
      return x;
    else
      return par[x] = find(par[x]);
  }
  void unite(int a, int b) { par[find(a)] = find(b); }
  bool isSame(int a, int b) { return find(a) == find(b); }
  vector<int> findRedundantConnection(vector<vector<int>> &edges) {
    int n = edges.size();
    init(n);
    for(auto &e : edges){
      if(isSame(e[0], e[1])){
        return e;
      }
      unite(e[0], e[1]);
    }
    return edges[n - 1];
  }
};
