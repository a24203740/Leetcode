#include "../includes.hpp"

class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>> &mat) {
    int R = mat.size();
    int C = mat[0].size();
    vector<int> ans(R*C);
    int id = 0;
    for(int did = 0; did <= R+C-2; did++) { 
      if(did % 2 == 0) {
        int c_st = max(0, did - R + 1);
        int c_ed = min(C - 1, did);
        for(int c = c_st; c <= c_ed; c++) {
          int r = did - c;
          ans[id++] = mat[r][c];
        }
      }
      else {
        int r_st = max(0, did-C+1);
        int r_ed = min(R-1, did);
        for(int r = r_st; r <= r_ed; r++) {
          int c = did - r;
          ans[id++] = mat[r][c];
        }
      }
    }
    return ans;
  }
};
