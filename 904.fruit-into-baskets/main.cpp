#include "../includes.hpp"

class Solution {
public:
  int totalFruit(vector<int> &fruits) {
    int l = 0, r = 0;
    int n = fruits.size();
    vector<int> count(n + 1, 0);
    int unique = 0;
    int ans = 0;
    while (l < n && r < n) {
      int cur = fruits[r];
      r++;
      count[cur]++;
      if(count[cur] == 1) {
        unique++;
        while(unique > 2) {
          count[fruits[l]]--;
          if(count[fruits[l]] == 0) {
            unique--;
          }
          l++;
        }
      }
      ans = max(ans, r - l);
    }
    return ans;
  }
};
