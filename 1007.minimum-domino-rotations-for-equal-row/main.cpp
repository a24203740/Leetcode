#include "../includes.hpp"
#include <iterator>

class Solution {
public:
  int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
    array<int, 2> upcount, bottomcount;
    int first = tops[0], second = bottoms[0];
    int n = tops.size();
    upcount.fill(0);
    bottomcount.fill(0);
    for (int i = 0; i < n; i++) {
      if (tops[i] != first && bottoms[i] != first) {
        first = -1;
      }
      if (tops[i] != second && bottoms[i] != second) {
        second = -1;
      }
      if (first == -1 && second == -1) {
        return -1;
      }
    }
    if (first == -1 || second == -1) {
      int available = max(first, second);
      for (int i = 0; i < n; i++) {
        if (available != tops[i]) {
          upcount[0]++;
        }
        if (available != bottoms[i]) {
          bottomcount[0]++;
        }
      }
      return min(upcount[0], bottomcount[0]);
    } else {
      for (int i = 0; i < n; i++) {
        if (first != tops[i]) {
          upcount[0]++;
        }
        if (first != bottoms[i]) {
          bottomcount[0]++;
        }
        if (second != tops[i]) {
          upcount[1]++;
        }
        if (second != bottoms[i]) {
          bottomcount[1]++;
        }
      }
      int ans1 = min(upcount[0], bottomcount[0]);
      int ans2 = min(upcount[1], bottomcount[1]);
      return min(ans1, ans2);
    }
  }
};
