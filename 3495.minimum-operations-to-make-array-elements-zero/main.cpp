#include "../includes.hpp"
#include <algorithm>
#include <iterator>

using appear = array<int, 15>;
using ll = long long;
class Solution {
public:
  long long minOperations(vector<vector<int>> &queries) {
    vector<ll> bound;
    ll ans = 0;
    bound.reserve(15);
    {
      ll counter = 1;
      for (int i = 0; i < 15; i++) {
        counter *= 4;
        bound.emplace_back(counter);
      }
    }
    for(const auto &v : queries) {
      appear app;
      app.fill(0);
      auto it = lower_bound(bound.begin(), bound.end(), v[0] + 1);
      auto it2 = lower_bound(bound.begin(), bound.end(), v[1] + 1);
      ll opsNeedToEliminateStart = distance(bound.begin(), it) + 1;
      ll opsNeedToEliminateEnd = distance(bound.begin(), it2) + 1;
      ll count;
      ll totalOps = 0;
      if (opsNeedToEliminateStart == opsNeedToEliminateEnd) {
        count = v[1] - v[0] + 1;
        totalOps = count * opsNeedToEliminateStart;
      }
      else {
        count = *it - v[0];
        totalOps += count * opsNeedToEliminateStart;
        count = v[1] - *(it2 - 1) + 1;
        totalOps += count * opsNeedToEliminateEnd;
        for(int i = opsNeedToEliminateStart + 1; i < opsNeedToEliminateEnd; i++) {
          count = bound[i - 1] - bound[i - 2];
          totalOps += count * i;
        }
      }
      ans += totalOps / 2;
      if(totalOps % 2) ans++;
    }
    return ans;
  }
};
