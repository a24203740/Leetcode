#include "../includes.hpp"

class Solution {
public:
  int findClosest(int x, int y, int z) {
    int distX = abs(z - x);
    int distY = abs(z - y);
    if (distX < distY) {
      return 1;
    } else if (distY < distX) {
      return 2;
    } else {
      return 0;
    }
  }
};
