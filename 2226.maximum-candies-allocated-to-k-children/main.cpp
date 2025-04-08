#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  bool canSatisfy(vector<int> &candies, ll k, int threshold) {
    for(auto candy : candies) {
      k -= (candy / threshold);
      if (k <= 0) {
        return true;
      }
    }
    return false;
  }
  int maximumCandies(vector<int> &candies, ll k) {
    int maxCandy = 0;
    int n = candies.size();
    for (int i = 0; i < n; i++) {
      maxCandy = max(maxCandy, candies[i]);
    }
    int l = 0, r = maxCandy;
    while (l < r) {
      int mid = l + (r - l + 1) / 2;
      if (canSatisfy(candies, k, mid)) {
        l = mid;
      } else {
        r = mid - 1;
      }
    }
    return l;
  }
};
