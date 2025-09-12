#include "../includes.hpp"

class Solution {
public:
  int lenOfVDiagonal(vector<vector<int>> &grid) {
    enum Direction { UP_RIGHT, DOWN_RIGHT, DOWN_LEFT, UP_LEFT };
    int R = grid.size();
    int C = grid[0].size();
    vector<vector<int>> alternative_length[4];
    for (int d = 0; d < 4; ++d) {
      alternative_length[d].assign(R, vector<int>(C, 0));
    }
    int dr[4] = {-1, 1, 1, -1};
    int dc[4] = {1, 1, -1, -1};
    for(int d = 0; d < 4; d++) {
      int r_init, r_end, r_step;
      int c_init, c_end, c_step;
      if(d == UP_RIGHT) {
        r_init = 0; r_end = R; r_step = 1;
        c_init = 0; c_end = C; c_step = 1;
      } else if(d == DOWN_RIGHT) {
        r_init = R - 1; r_end = -1; r_step = -1;
        c_init = 0; c_end = C; c_step = 1;
      } else if(d == DOWN_LEFT) {
        r_init = R - 1; r_end = -1; r_step = -1;
        c_init = C - 1; c_end = -1; c_step = -1;
      } else { // UP_LEFT
        r_init = 0; r_end = R; r_step = 1;
        c_init = C - 1; c_end = -1; c_step = -1;
      }
      for(int r = r_init; r != r_end; r += r_step) {
        for(int c = c_init; c != c_end; c += c_step) {
          if(grid[r][c] == 1) {
            alternative_length[d][r][c] = 0;
            continue;
          }
          int pr = r + dr[d];
          int pc = c + dc[d];
          if(pr >= 0 && pr < R && pc >= 0 && pc < C) {
            // (0,2), (2,0), (1,1)
            // while (1,1) is impossible as we have grid[r][c] != 1
            if(grid[pr][pc] + grid[r][c] == 2) {
              alternative_length[d][r][c] = alternative_length[d][pr][pc] + 1;
              continue;
            }
            alternative_length[d][r][c] = 1;
          } else {
            alternative_length[d][r][c] = 1;
          }
        }
      }
    }
    // for(int d = 0; d < 4; d++) {
    //   if (d == 0) cout << "UP_RIGHT" << endl;
    //   else if (d == 1) cout << "DOWN_RIGHT" << endl;
    //   else if (d == 2) cout << "DOWN_LEFT" << endl;
    //   else if (d == 3) cout << "UP_LEFT" << endl;
    //   for(int r = 0; r < R; r++) {
    //     for(int c = 0; c < C; c++) {
    //       cout << alternative_length[d][r][c] << " ";
    //     }
    //     cout << endl;
    //   }
    // }
    int ans = 0;
    for (int r = 0; r < R; r++) {
      for(int c = 0; c < C; c++) {
        if(grid[r][c] != 1) continue;
        int len = 1;
        for(int d = 0; d < 4; d++) {
          int pr = r + dr[d];
          int pc = c + dc[d];
          int turn_angle = (d + 1) % 4;
          if(pr >= 0 && pr < R && pc >= 0 && pc < C && grid[pr][pc] == 2) {
            int l = alternative_length[d][pr][pc];
            int nr = pr;
            int nc = pc;
            if(l <= 0) continue;
            for(int i = 0; i < l; i++) {
              len = max(len, 1 + i + alternative_length[turn_angle][nr][nc]);
              nr += dr[d];
              nc += dc[d];
            }
          }
        }
        ans = max(ans, len);
      }
    }
    return ans;
    
  }
};
