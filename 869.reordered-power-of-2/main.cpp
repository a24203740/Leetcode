#include "../includes.hpp"

using digits = array<int, 10>;
class Solution {
public:
  bool equal(const digits& a, const digits& b) {
    for(int i = 0; i < 10; i++) {
      if(a[i] != b[i]) return false;
    }
    return true;
  }
  bool reorderedPowerOf2(int n) {
    vector<digits> fingerprint(31);
    for(int i = 0; i < 31; i++) {
      int x = (1<<i);
      while(x > 0) {
        fingerprint[i][x % 10]++;
        x /= 10;
      }
    }
    int x = n;
    digits d;
    while(x > 0) {
      d[x % 10]++;
      x /= 10;
    }
    for(int i = 0; i < 31; i++) {
      if(equal(fingerprint[i], d)) {
        return true;
      }
    }
    return false;
    
  }
};
