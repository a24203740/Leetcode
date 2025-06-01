#include "../includes.hpp"

using ti = tuple<int, int, int, bool>;
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
    pq.push({0, 0, 0, false});
    while (!pq.empty()) {
      auto [d, r, c, even] = pq.top();
      pq.pop();
      if (dis[r][c] < d) continue;
      cout << d << " " << r << " " << c << " " << even << endl;
      for (int i = 0; i < 4; i++) {
        int nr = r + dr[i], nc = c + dc[i];
        if (!inBounds(nr, nc)) continue;
        int res = max(d, moveTime[nr][nc]);
        if(even) res++;
        else res += 2;
        if(dis[nr][nc] > res) {
          dis[nr][nc] = res;
          pq.push({res, nr, nc, !even});
        }
      }
    }
    return dis[R - 1][C - 1];
  }
};
