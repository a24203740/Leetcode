#include "../includes.hpp"

class Solution {
public:
  int countHillValley(vector<int> &nums) {
    bool first = true, upSlope = false;
    int n = nums.size();
    int ans = 0;
    for (int i = 1; i < n; i++) {
      if (first) {
        if (nums[i] > nums[i - 1]) {
          upSlope = true;
          first = false;
        } else if (nums[i] < nums[i - 1]) {
          upSlope = false;
          first = false;
        }
      } else {
        if (!upSlope && nums[i] > nums[i - 1]) {
          ans++;
          upSlope = true;
        } else if (upSlope && nums[i] < nums[i - 1]) {
          ans++;
          upSlope = false;
        }
      }
    }
    return ans;
  }
};
