#include "../includes.hpp"

const int MAX = 64; // 60 may be enough, but just in case
using ll = long long;
class Solution {
public:
  int makeTheIntegerZero(int num1, int num2) {
    ll x1 = num1, x2 = num2;
    for(int i = 1; i <= MAX; i++) {
      ll target = x1 - i * x2;
      if(target <= 0) return -1;
      bitset<MAX> bs(target);
      if(bs.count() <= i && target >= i) return i;
    }
    return -1;
  }
};
