#include "../includes.hpp"
#include <bitset>

using ti = tuple<int, int, int>;
const int dr[4] = {0, 1, 0, -1};
const int dc[4] = {1, 0, -1, 0};
class Solution {
public:
  int minTimeToReach(vector<vector<int>> &moveTime) {
    int R = moveTime.size(), C = moveTime[0].size();
    vector<vector<int>> dis(R, vector<int>(C, 1e9 + 1e8));
    auto inBounds = [&](int r, int c) -> bool {
      return r >= 0 && r < R && c >= 0 && c < C;
    };
    priority_queue<ti, vector<ti>, greater<ti>> pq;
    dis[0][0] = 0;
    pq.push({0, 0, 0});
    while (!pq.empty()) {
      auto [d, r, c] = pq.top();
      pq.pop();
      if (dis[r][c] < d) continue;
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (!inBounds(nr, nc)) continue;
        int res = max(d, moveTime[nr][nc]) + 1;
        if(dis[nr][nc] > res) {
          dis[nr][nc] = res;
          pq.push({res, nr, nc});
        }
      }
    }
    return dis[R - 1][C - 1];
  }
};
