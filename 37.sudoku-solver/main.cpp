#include "../includes.hpp"
#include <bitset>

using row = bitset<9>;
using col = bitset<9>;
using box = bitset<9>;
class Solution {
public:
  void solveSudoku(vector<vector<char>> &board) {
    vector<row> rows(9, {0});
    vector<col> cols(9, {0});
    vector<box> boxes(9, {0});
    int set = 0;
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] != '.') {
          int num = board[r][c] - '1';
          rows[r].set(num);
          cols[c].set(num);
          boxes[(r / 3) * 3 + c / 3].set(num);
          set++;
        }
      }
    }
    vector<vector<pair<int, bitset<9>>>> possiblities(
        9, vector<pair<int, bitset<9>>>(9, {0, {0}}));
    queue<tuple<int, int, int>> q;
    for (int r = 0; r < 9; ++r) {
      for (int c = 0; c < 9; ++c) {
        if (board[r][c] == '.') {
          for (int num = 0; num < 9; ++num) {
            if (!rows[r].test(num) && !cols[c].test(num) &&
                !boxes[(r / 3) * 3 + c / 3].test(num)) {
              possiblities[r][c].first++;
              possiblities[r][c].second.set(num);
            }
          }
          if (possiblities[r][c].first == 1) {
            q.push({r, c, possiblities[r][c].second._Find_first()});
            possiblities[r][c].second.reset(); // to avoid pushing again
            possiblities[r][c].first = 0;
          }
        }
      }
    }
    auto solveSubSudoku = [&]() -> bool {
      while (!q.empty()) {
        set++;
        auto [r, c, num] = q.front();
        if (rows[r].test(num) || cols[c].test(num) ||
            boxes[(r / 3) * 3 + c / 3].test(num)) {
          // conflict, backtrack
          // cout << "conflict at " << r << "," << c << " with " << num + 1 << endl;
          return false;
        }
        q.pop();
        board[r][c] = num + '1';
        rows[r].set(num);
        cols[c].set(num);
        boxes[(r / 3) * 3 + c / 3].set(num);
        for (int cc = 0; cc < 9; cc++) {
          if (board[r][cc] == '.' && possiblities[r][cc].second.test(num)) {
            possiblities[r][cc].second.reset(num);
            possiblities[r][cc].first--;
            if (possiblities[r][cc].first == 1) {
              q.push({r, cc, possiblities[r][cc].second._Find_first()});
              possiblities[r][cc].second.reset(); // to avoid pushing again
              possiblities[r][cc].first = 0;
            }
          }
        }
        for (int rr = 0; rr < 9; rr++) {
          if (board[rr][c] == '.' && possiblities[rr][c].second.test(num)) {
            possiblities[rr][c].second.reset(num);
            possiblities[rr][c].first--;
            if (possiblities[rr][c].first == 1) {
              q.push({rr, c, possiblities[rr][c].second._Find_first()});
              possiblities[rr][c].second.reset(); // to avoid pushing again
              possiblities[rr][c].first = 0;
            }
          }
        }
        int br_st = (r / 3); br_st *= 3;
        int bc_st = (c / 3); bc_st *= 3;
        for (int rr = br_st; rr < br_st + 3; rr++) {
          for (int cc = bc_st; cc < bc_st + 3; cc++) {
            if (board[rr][cc] == '.' && possiblities[rr][cc].second.test(num)) {
              possiblities[rr][cc].second.reset(num);
              possiblities[rr][cc].first--;
              if (possiblities[rr][cc].first == 1) {
                q.push({rr, cc, possiblities[rr][cc].second._Find_first()});
                possiblities[rr][cc].second.reset(); // to avoid pushing again
                possiblities[rr][cc].first = 0;
              }
            }
          }
        }
      } 
      // for (int r = 0; r < 9; ++r) {
      //   for (int c = 0; c < 9; ++c) {
      //     cout << board[r][c] << " ";
      //   }
      //   cout << endl;
      // }
      return true;
    };
    solveSubSudoku();
    if (set == 81) return;
    auto enumAllInFirst = [&](const auto &self) -> bool {
      for (int r = 0; r < 9; ++r) {
        for (int c = 0; c < 9; ++c) {
          if (board[r][c] == '.') {
            for (int num = 0; num < 9; ++num) {
              if (possiblities[r][c].second.test(num)) {
                int tp = set;
                vector<vector<char>> tp_board = board;
                vector<row> tp_rows = rows;
                vector<col> tp_cols = cols;
                vector<box> tp_boxes = boxes;
                vector<vector<pair<int, bitset<9>>>> tp_possiblities = possiblities;
                q.push({r, c, num});
                board[r][c] = num + '1';
                possiblities[r][c].second.reset(); // to avoid pushing again
                possiblities[r][c].first = 0;
                bool res = solveSubSudoku();
                // for(int rr = 0; rr < 9; rr++) {
                //   for(int cc = 0; cc < 9; cc++) {
                //     cout << board[rr][cc];
                //     if(board[rr][cc] != tp_board[rr][cc]) {
                //       cout << "* ";
                //     }
                //     else cout << "  ";
                //   }
                //   cout << endl;
                // }
                if (set == 81) return true;
                if (res && self(self)) return true;
                // backtrack
                while (!q.empty()) q.pop();
                set = tp;
                tp_board.swap(board);
                tp_rows.swap(rows);
                tp_cols.swap(cols);
                tp_boxes.swap(boxes);
                tp_possiblities.swap(possiblities);
              }
            }
            return false;
          }
        }
      }
      return true; // all filled
    };
    enumAllInFirst(enumAllInFirst);
  }
};
