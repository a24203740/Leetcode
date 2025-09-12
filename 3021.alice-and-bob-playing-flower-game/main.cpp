#include "../includes.hpp"

using ll = long long int;
class Solution {
public:
  long long flowerGame(int n, int m) {
    ll ans = 0;
    // odd * even + even * odd
    ll odd1 = n/2 + n%2, even1 = n/2;
    ll odd2 = m/2 + m%2, even2 = m/2;
    return odd1 * even2 + even1 * odd2;
  }
};
