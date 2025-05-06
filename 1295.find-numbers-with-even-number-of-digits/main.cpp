#include "../includes.hpp"

class Solution {
public:
  inline int findDigits(int n) {
    if (n == 0)
      return 1;
    int count = 0;
    while (n > 0) {
      n /= 10;
      count++;
    }
    return count;
  }
  int findNumbers(vector<int> &nums) {
    int ans = 0;
    for (auto &n : nums) {
      if (findDigits(n) % 2 == 0) {
        ans++;
      }
    }
    return ans;
  }
};
