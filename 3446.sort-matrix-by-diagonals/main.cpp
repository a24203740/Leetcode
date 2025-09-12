#include "../includes.hpp"

using point = pair<int, int>;
class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {
    int R = grid.size(), C = grid[0].size();
    vector<int> tp(R, 1e9);
    point up{0, C-1}, down{R-1, 0};
    for(int i = 0; i < R; i++) {
      point upit = up;
      int l = i+1;
      // cout << l << endl;
      for(int j = 0; j < l; j++) {
        // cout << upit.first << " " << upit.second << endl;
        tp[j] = grid[upit.first][upit.second];
        upit.first++;
        upit.second++;
      }
      sort(tp.begin(), tp.begin()+l);
      upit = up;
      for(int j = 0; j < l; j++) {
        grid[upit.first][upit.second] = tp[j];
        upit.first++;
        upit.second++;
      }
      // cout << "----" << endl;
      point downit = down;
      for(int j = 0; j < l; j++) {
        // cout << downit.first << " " << downit.second << endl;
        tp[j] = grid[downit.first][downit.second];
        downit.first++;
        downit.second++;
      }
      sort(tp.begin(), tp.begin()+l, greater<int>()); // sort in descending order
      downit = down;
      for(int j = 0; j < l; j++) {
        grid[downit.first][downit.second] = tp[j];
        downit.first++;
        downit.second++;
      }
      up.second--;
      down.first--;
    }
    int l = R;
    point it{0, 0};
    for(int j = 0; j < l; j++) {
      tp[j] = grid[it.first][it.second];
      it.first++;
      it.second++;
    }
    sort(tp.begin(), tp.begin()+l, greater<int>());
    it = {0, 0};
    for(int j = 0; j < l; j++) {
      grid[it.first][it.second] = tp[j];
      it.first++;
      it.second++;
    }
    return grid;
  }
};
