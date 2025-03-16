#include "includes.hpp"
#include <bitset>

class Solution {
public:
  vector<bool> checkIfPrerequisite(int numCourses,
                                   vector<vector<int>> &prerequisites,
                                   vector<vector<int>> &queries) {
    vector<bitset<100>> parent(numCourses, bitset<100>(0));
    vector<int> indeg(numCourses, 0);
    vector<vector<int>> adjList(numCourses);
    for (auto &e : prerequisites) {
      indeg[e[1]]++;
      adjList[e[0]].push_back(e[1]);
    }
    queue<int> q;
    for(int i = 0; i < numCourses; i++) {
      if (indeg[i] == 0) {
        q.push(i);
      }
    }
    while(!q.empty()) {
      int u = q.front();
      q.pop();
      for(auto v: adjList[u]) {
        parent[v] |= parent[u];
        parent[v].set(u);
        indeg[v]--;
        if (indeg[v] == 0) {
          q.push(v);
        }
      }
    }
    vector<bool> res;
    for(auto q: queries) {
      if (parent[q[1]].test(q[0])) {
        res.push_back(true);
      }
      else {
        res.push_back(false);
      }
    }
    return res;
  }
};
