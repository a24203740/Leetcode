#include "../includes.hpp"

using pii = pair<int, int>;
using edgesSet = bitset<1005>;
class Solution {
public:
  vector<int> XORVal;
  vector<vector<pii>> adj;
  vector<int> par;
  int DFS(int cur, int p, const vector<int> &nums) {
    int x = 0;
    for (auto [next, eid] : adj[cur]) {
      if (next == p)
        continue;
      x ^= DFS(next, cur, nums);
    }
    x ^= nums[cur];
    XORVal[cur] = x;
    par[cur] = p;
    return x;
  }
  int ans = 1e9;
  int totalXOR = 0;
  void calcDiffer(int inSet, int outSet, const edgesSet& s, const edgesSet& parentPath,
                  const vector<vector<int>> &edges, int edgeId) {
    int m = edges.size();
    cout << "remove " << edges[edgeId][0] << " " << edges[edgeId][1] << endl;
    cout << "inset: " << inSet << "\n";
    cout << "outset: " << outSet << "\n";
    for (int i = 0; i < m; i++) {
      if (i == edgeId)
        continue;
      int subRoot = edges[i][0], p = edges[i][1];
      if (par[subRoot] != p) {
        swap(subRoot, p);
      }
      cout << "then remove " << subRoot << " " << p << endl;
      int a, b, c;
      if (s.test(i)) {
        cout << "is in subtree\n";
        a = XORVal[subRoot];
        b = inSet ^ a;
        c = outSet;
      } else {
        cout << "is NOT in subtree\n";
        a = XORVal[subRoot];
        b = outSet ^ a;
        if(parentPath.test(i)) {
          a ^= inSet;
        }
        c = inSet;
      }
      int maxmium = max(a, b);
      maxmium = max(maxmium, c);
      int minimum = min(a, b);
      minimum = min(minimum, c);
      cout << a << " " << b << " " << c << '\n';
      cout << maxmium << " " << minimum << " " << maxmium - minimum << '\n';
      ans = min(ans, maxmium - minimum);
    }
    return;
  }
  edgesSet DFS2(int cur, int p, const vector<vector<int>> &edges, edgesSet& parentPath) {
    edgesSet subTree{0};
    int pid = -1;
    for (auto [next, eid] : adj[cur]) {
      if (next == p) {
        pid = eid;
        continue;
      }
      parentPath.set(eid);
      subTree |= DFS2(next, cur, edges, parentPath);
      parentPath.reset(eid);
    }
    int inSet = XORVal[cur], outSet = totalXOR ^ inSet;
    if (pid != -1) {
      calcDiffer(inSet, outSet, subTree, parentPath, edges, pid);
      subTree.set(pid);
    }
    return subTree;
  }

  int minimumScore(vector<int> &nums, vector<vector<int>> &edges) {
    int n = nums.size();
    adj.resize(n);
    par.resize(n, -1);
    XORVal.resize(n);
    for (int i = 0; i < n; i++) {
      totalXOR ^= nums[i];
    }
    for (int i = 0; i < n - 1; i++) {
      const vector<int> &e = edges[i];
      adj[e[0]].push_back({e[1], i});
      adj[e[1]].push_back({e[0], i});
    }
    DFS(0, -1, nums);
    edgesSet parentPath{0};
    DFS2(0, -1, edges, parentPath);
    return ans;
  }
};
