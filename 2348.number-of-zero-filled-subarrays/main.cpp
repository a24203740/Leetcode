#include "../includes.hpp"

class Solution {
public:
  long long zeroFilledSubarray(vector<int> &nums) {
    auto calculate = [](int n) {
      return (static_cast<long long>(n) * (n + 1)) / 2;
    };
    int prev = 0;
    nums.push_back(1);
    int n = nums.size();
    long long ans = 0;
    for(int i = 0; i < n; i++) {
      if(nums[i] == 0) {
        prev++;
      } else {
        if(prev > 0) {
          ans += calculate(prev);
        }
        prev = 0;
      }
    }
    return ans;
  }
};
