#include "../includes.hpp"

class Solution {
public:
  bool isPowerOfFour(int n) {
    for(int i = 0; i < 31; i++) {
      if((1 << i) & n) { 
        return ((1 << i) == n) && (i % 2 == 0);
      }
    }
    return false;
  }
};
