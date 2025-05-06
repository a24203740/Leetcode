#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  int numberOfArrays(vector<int> &differences, int lower, int upper) {
    int n = differences.size();
    ll diffMin = 1e15, diffMax = -1e15, sum = 0;
    for (int i = 0; i < n; i++) {
      sum += differences[i];
      diffMin = min(diffMin, sum);
      diffMax = max(diffMax, sum);
    }
    ll rangeMax = upper - diffMax;
    ll rangeMin = lower - diffMin;
    if(rangeMin < lower) rangeMin = lower;
    if(rangeMax > upper) rangeMax = upper;
    return max(rangeMax - rangeMin + 1, 0LL);
  }
};
