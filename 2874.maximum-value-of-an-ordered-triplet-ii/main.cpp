#include "../includes.hpp"

class Solution {
public:
  long long maximumTripletValue(vector<int> &nums) {
    int n = nums.size();
    vector<int> suf(n);
    suf[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--) {
      suf[i] = max(suf[i + 1], nums[i]);
    }
    long long int pre = nums[0];
    long long int ans = 0;
    for (int i = 1; i < n - 1; i++) {
      ans = max(ans, (pre - nums[i]) * suf[i + 1]);
      pre = max(pre, (long long)nums[i]);
    }
    return ans;
  }
};
