#include "../includes.hpp"
#include <cstddef>

const int UNINIT = 1000000;
struct trNode {
  vector<int> dis{};
  vector<int> nei{};
  vector<int> inDomain{};
  trNode(int n) {
    dis.assign(n, UNINIT);
    nei.reserve(n);
    inDomain.reserve(n);
  }
};
using tree = vector<trNode>;
class Solution {
public:
  void DFS(int par, int cur, tree& t, int k) {
    trNode& cN = t[cur];
    cN.dis[cur] = 0;
    cN.inDomain.push_back(cur);
    for(auto e: cN.nei) {
      if(e == par)continue;
      DFS(cur, e, t, k);
      trNode& child = t[e];
      for(auto d: child.inDomain) {
        if(child.dis[d] + 1 <= k) {
          cN.inDomain.push_back(d);
          cN.dis[d] = child.dis[d] + 1;
        }
      }
    }
  }
  void mergeWithParent(int par, int cur, tree& t, int k) {
    trNode& cN = t[cur];
    if (par != -1) {
      trNode& pN = t[par];
      for(auto c : pN.inDomain) {
        if(cN.dis[c] == UNINIT && pN.dis[c] + 1 <= k) {
          cN.inDomain.push_back(c);
          cN.dis[c] = pN.dis[c] + 1;
        }
      }
    }
    for(auto e: cN.nei) {
      if(e == par) continue;
      mergeWithParent(cur, e, t, k);
    }
  }
  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2, int k) {
    int n1 = edges1.size() + 1;
    int n2 = edges2.size() + 1;
    if(k == 0) {
      return vector<int>(n1, 1);
    }
    tree tr1(n1, trNode(n1));
    tree tr2(n2, trNode(n2));
    for(const auto& e: edges1) {
      tr1[e[0]].nei.push_back(e[1]);
      tr1[e[1]].nei.push_back(e[0]);
    }
    for(const auto& e: edges2) {
      tr2[e[0]].nei.push_back(e[1]);
      tr2[e[1]].nei.push_back(e[0]);
    }
    DFS(-1, 0, tr1, k);
    mergeWithParent(-1, 0, tr1, k);
    DFS(-1, 0, tr2, k-1);
    mergeWithParent(-1, 0, tr2, k-1);
    size_t bouns = 0;
    for(int i = 0; i < n2; i++) {
      bouns = max(bouns, tr2[i].inDomain.size());
    }
    vector<int> ans(n1, 0);
    for(int i = 0; i < n1; i++) {
      ans[i] = bouns + tr1[i].inDomain.size();
    }
    return ans;
  }
};
