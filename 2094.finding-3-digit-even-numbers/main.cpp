#include "../includes.hpp"

class Solution {
public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    array<int, 10> app = {0};
    for (int d : digits) {
      app[d]++;
    }
    vector<int> ans; ans.reserve(500);
    int tp = 0;
    for(int h = 1; h <= 9; h++) {
      if(!app[h])continue;
      app[h]--;
      tp = h * 100;
      for(int t = 0; t <= 9; t++) {
        tp += 10;
        if(!app[t])continue;
        app[t]--;
        for(int d = 0; d <= 8; d+=2) {
          if(!app[d])continue;
          ans.push_back(tp - 10 + d);
        }
        app[t]++;
      }
      app[h]++;
    }
    return ans;
  }
};
