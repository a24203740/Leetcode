#include "../includes.hpp"

class Solution {
public:
  long long distributeCandies(int n, int limit) {
    long long ans = 0;
    // n - start < limit * 2
    int start = max(n - limit * 2, 0);
    int end = min(n, limit);
    for(int first = start; first <= end; first++) {
      int left = n - first;
      int secondMin = 0, secondMax = min(left, limit);
      if(left > limit) secondMin = left - limit;
      if(secondMin > limit) continue;
      ans += (secondMax - secondMin + 1);
    }
    return ans;
  }
};
