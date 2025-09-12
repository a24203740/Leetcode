#include "../includes.hpp"

class Solution {
public:
  int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
    long long int maxLen = 0;
    int maxArea = 0;
    for(const auto& v: dimensions) {
      long long int len = (long long int)v[0] * v[0] + (long long int)v[1] * v[1];
      if(len > maxLen) {
        maxLen = len;
        maxArea = v[0] * v[1];
      } else if(len == maxLen) {
        maxArea = max(maxArea, v[0] * v[1]);
      }
    }
    return maxArea;
  }
};
