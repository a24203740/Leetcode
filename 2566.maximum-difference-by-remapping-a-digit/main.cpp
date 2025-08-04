#include "../includes.hpp"

class Solution {
public:
  int minMaxDifference(int num) {
    string maximum = to_string(num);
    string minimum = maximum;
    char minTarget = minimum[0];
    char maxTarget = maximum[0];
    int n = maximum.size();
    for (int i = 0; i < n; ++i) {
      if(maxTarget == '9' && maximum[i] != '9') {
        maxTarget = maximum[i];
      }
      if (maximum[i] == maxTarget) {
        maximum[i] = '9';
      }
      if (minimum[i] == minTarget) {
        minimum[i] = '0';
      }
    }
    return stoi(maximum) - stoi(minimum);
  }
};
