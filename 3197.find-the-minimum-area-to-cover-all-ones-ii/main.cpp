#include "../includes.hpp"

struct bound {
  int mn;
  int mx;
};
class Solution {
public:
  int minimumSum(vector<vector<int>> &grid) {
    int R = grid.size();
    int C = grid[0].size();
    int ans = solve(grid);
    vector<vector<int>> rotatedGrid(C, vector<int>(R, 0));
    for(int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
        rotatedGrid[c][r] = grid[r][c];
      }
    }
    ans = min(ans, solve(rotatedGrid));
    return ans;
  }
  int solve(vector<vector<int>> &grid) {
    int R = grid.size();
    int C = grid[0].size();
    vector<bound> rows(R, {C, -1});
    vector<bound> cols(C, {R, -1});
    for (int r = 0; r < R; r++) {
      for (int c = 0; c < C; c++) {
        if (grid[r][c] == 1) {
          rows[r].mn = min(rows[r].mn, c);
          rows[r].mx = max(rows[r].mx, c);
          cols[c].mn = min(cols[c].mn, r);
          cols[c].mx = max(cols[c].mx, r);
        }
      }
    }
    auto solveLeftRight = [&](int top, int bottom, int left, int right) {
      int ans = 1e9;
      vector<bound> subcols(C, {R, -1});
      for(int r = top; r < bottom; r++) {
        for(int c = left; c < right; c++) {
          if (grid[r][c] == 1) {
            subcols[c].mn = min(subcols[c].mn, r);
            subcols[c].mx = max(subcols[c].mx, r);
          }
        }
      }
      for(int mid = left; mid < right-1; mid++) {
        int ll = -1, lr = -1, rl = -1, rr = -1;
        bound leftBound = {R, -1}, rightBound = {R, -1};
        for(int l = left; l <= mid; l++) {
          if (subcols[l].mx != -1) {
            leftBound.mn = min(leftBound.mn, subcols[l].mn);
            leftBound.mx = max(leftBound.mx, subcols[l].mx);
            if (ll == -1) ll = l;
            lr = l;
          }
        }
        for(int r = mid+1; r < right; r++) {
          if (subcols[r].mx != -1) {
            rightBound.mn = min(rightBound.mn, subcols[r].mn);
            rightBound.mx = max(rightBound.mx, subcols[r].mx);
            if (rl == -1) rl = r;
            rr = r;
          }
        }
        if (ll == -1 || rl == -1) continue;
        // cout << "mid" << ": " << mid << endl;
        // cout << ll << " " << lr << " " << leftBound.mn << " " << leftBound.mx << endl;
        // cout << rl << " " << rr << " " << rightBound.mn << " " << rightBound.mx << endl;
        int res = (lr - ll + 1) * (leftBound.mx - leftBound.mn + 1) + (rr - rl + 1) * (rightBound.mx - rightBound.mn + 1);
        ans = min(ans, res);
      }
      return ans;
    };
    int ans = 1e9;
    // top, downleft, downright case
    {
      int top = -1;
      for (int r = 0; r < R; r++) {
        if (rows[r].mx != -1) {
          top = r;
          break;
        }
      }
      if (top != -1) {
        int left = rows[top].mn;
        int right = rows[top].mx;
        for(int bot = top; bot < R-1; bot++) {
          if (rows[bot].mx == -1) continue;
          // cout << "top: " << top << endl;
          // cout << "bot: " << bot << endl;
          left = min(left, rows[bot].mn);
          right = max(right, rows[bot].mx);
          // cout << "left: " << left << endl;
          // cout << "right: " << right << endl;
          int area = (bot - top + 1) * (right - left + 1);
          if (area == 0) continue;
          int anotherArea = solveLeftRight(bot + 1, R, 0, C);
          ans = min(ans, area + anotherArea);
        }
      }
    }
    // cout << "case(1), curr ans: " << ans << endl;
    // bot, topleft, topright case
    {
      int bottom = -1;
      for (int r = R - 1; r >= 0; r--) {
        if (rows[r].mx != -1) {
          bottom = r;
          break;
        }
      }
      if (bottom != -1) {
        int left = rows[bottom].mn;
        int right = rows[bottom].mx;
        for(int top = bottom; top > 0; top--) {
          if (rows[top].mx == -1) continue;
          left = min(left, rows[top].mn);
          right = max(right, rows[top].mx);
          int area = (bottom - top + 1) * (right - left + 1);
          if (area == 0) continue;
          int anotherArea = solveLeftRight(0, top, 0, C);
          ans = min(ans, area + anotherArea);
        }
      }
    }
    // cout << "case(2), curr ans: " << ans << endl;
    // left, mid, right case
    {
      int left = -1;
      for (int c = 0; c < C; c++) {
        if (cols[c].mx != -1) {
          left = c;
          break;
        }
      }
      if (left != -1) {
        int top = cols[left].mn;
        int bottom = cols[left].mx;
        for(int right = left; right < C-2; right++) {
          if (cols[right].mx == -1) continue;
          top = min(top, cols[right].mn);
          bottom = max(bottom, cols[right].mx);
          // cout << "top: " << top << endl;
          // cout << "bot: " << bottom << endl;
          // cout << "left: " << left << endl;
          // cout << "right: " << right << endl;
          int area = (right - left + 1) * (bottom - top + 1);
          if (area == 0) continue;
          int anotherArea = solveLeftRight(0, R, right + 1, C);
          ans = min(ans, area + anotherArea);
        }
      }
    }
    // cout << "case(3), curr ans: " << ans << endl;
    return ans;
  }
};
