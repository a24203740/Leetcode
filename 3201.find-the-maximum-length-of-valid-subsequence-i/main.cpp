#include "../includes.hpp"

class Solution {
public:
  int maximumLength(vector<int> &nums) {
    int n = nums.size();
    int odd = 0, even = 0, alt = 0;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      if(nums[i] % 2 == 0) {
        even++;
        if (prev == 1) {
          alt++;
        }
        prev = 0;
      } else {
        odd++;
        if (prev == 0) {
          alt++;
        }
        prev = 1;
      }
    }
    int ans = max(odd, even);
    ans = max(ans, alt + 1);
    return ans;
  }
};
