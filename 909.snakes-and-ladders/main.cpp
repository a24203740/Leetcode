#include "../includes.hpp"

class Solution {
public:
  pair<int, int> labelToPosition(int label, int n) {
    label--;
    int row = label / n;
    int colOffset = label % n;
    if (row % 2 == 1)
      colOffset *= -1;
    int colBase = (row % 2 == 0) ? 0 : n - 1;
    return {n - row - 1, colBase + colOffset};
  }
  int snakesAndLadders(vector<vector<int>> &board) {
    int n = board.size();
    int lim = n * n;
    int level = 0;
    queue<int> q;
    bitset<408> visited{0};
    vector<array<int, 6>> adjEdge(lim, array<int, 6>{-1});
    for (int i = 1; i <= lim; i++) {
      for (int d = 1; d <= 6; d++) {
        if (i + d > lim)
          break;
        auto [r, c] = labelToPosition(i + d, n);
        if (board[r][c] == -1)
          adjEdge[i][d - 1] = i + d;
        else
          adjEdge[i][d - 1] = board[r][c];
      }
    }
    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
      cout << "Level: " << level << endl;
      int N = q.size();
      while (N--) {
        int cur = q.front();
        cout << cur << " ";
        q.pop();
        for (int d = 0; d < 6; d++) {
          int next = adjEdge[cur][d];
          if (next == -1)
            continue;
          if (next == lim)
            return level + 1;
          if (!visited[next]) {
            visited[next] = 1;
            q.push(next);
          }
        }
      }
      cout << endl;
      level++;
    }
    return -1;
  }
};
