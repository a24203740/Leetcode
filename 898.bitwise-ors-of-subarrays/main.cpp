#include "../includes.hpp"

class Solution {
public:
  int subarrayBitwiseORs(vector<int> &arr) {
    set<int> res;
    int n = arr.size();
    // possible backward length <= 32
    // because to produce a new bitwise OR, we need to have at least one new bit
    for (int i = 0; i < n; i++) {
      int cur = arr[i];
      int prefix = 0;
      int it = i - 1;
      res.insert(cur);
      while (it >= 0 && cur != prefix) {
        cur |= arr[it];
        prefix |= arr[it];
        res.insert(cur);
        it--;
      }
    }
    return res.size();
  }
};
