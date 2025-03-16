#include "../includes.hpp"

class Solution {
public:
  int numOfSubarrays(vector<int> &arr) {
    int oddSumCount = 0;
    int evenSumCount = 0;
    int oddState[2] = {0, 0}, evenState[2] = {0, 0};
    int flag = 0;
    const int MOD = 1e9 + 7;
    for (auto x : arr) {
      if (x % 2 == 0) {
        oddState[flag] = oddState[1 - flag];
        evenState[flag] = evenState[1 - flag] + 1;
      }
      if (x % 2 == 1) {
        oddState[flag] = evenState[1 - flag] + 1;
        evenState[flag] = oddState[1 - flag];
      }
      oddSumCount = (oddSumCount + oddState[flag]) % MOD;
      evenSumCount = (evenSumCount + evenState[flag]) % MOD;
      flag = 1 - flag;
    }
    return oddSumCount;
  }
};
