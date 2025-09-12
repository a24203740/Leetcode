#include "../includes.hpp"

class Solution {
public:
  int numberOfPairs(vector<vector<int>> &points) {
    array<vector<int>, 51> count;
    for (const auto &p : points) {
      count[p[0]].push_back(p[1]);
    }
    for(int i = 0; i < 51; i++) {
      sort(count[i].begin(), count[i].end());
    }
    int ans = 0;
    int P = points.size();
    for (int i = 0; i < P; i++) {
      auto &v = points[i];
      int x0 = v[0], y0 = v[1];
      for(int j = 0; j < P; j++) {
        if(j == i) continue;
        auto &u = points[j];
        int x1 = u[0], y1 = u[1];
        if(x0 < x1 || y0 > y1) continue;
        bool success = true;
        for(int x = x1; x <= x0; x++) {
          int st = y0;
          if(x == x0) st = y0+1;
          auto &w = count[x];
          auto it = lower_bound(w.begin(), w.end(), st);
          if (it != w.end()) {
            if(x != x1 && *it <= y1) {
              success = false;
              break;
            } else if(x == x1 && *it < y1) {
              success = false;
              break;
            }
          }
        }
        if(success) ans++;
      }
    }
    return ans;
  }
};
