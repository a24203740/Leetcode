#include "../includes.hpp"

using vi = vector<int>;
class Solution {
public:
  int ans = 0;
  vi xors;
  int subsetXORSum(vector<int> &nums) {
    xors.reserve(9000);
    xors.push_back(0);
    for(auto x : nums) {
      for(auto y : xors) {
        xors.push_back(x ^ y);
        ans += x ^ y;
      }
    }
    return ans; 
  }
};
