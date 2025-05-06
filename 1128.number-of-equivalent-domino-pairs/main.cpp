#include "../includes.hpp"

class Solution {
public:
  int numEquivDominoPairs(vector<vector<int>> &dominoes) {
    vector<int> appear(100, 0);
    int n = dominoes.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
      int a = dominoes[i][0], b = dominoes[i][1];
      if (a < b) {
        swap(a, b);
      }
      ans += appear[a * 10 + b];
      appear[a * 10 + b]++;
    }
    return ans;
  }
};
