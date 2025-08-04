#include "../includes.hpp"

class Solution {
public:
  int maximumUniqueSubarray(vector<int> &nums) {
    bitset<10001> appear;
    appear.reset();
    int n = nums.size();
    int r = 0;
    int ans = 0;
    int sum = 0;
    for(int l = 0; l < n; l++) {
      while (r < n && !appear.test(nums[r])) {
        appear.set(nums[r]);
        sum += nums[r];
        r++;
      }
      ans = max(ans, sum);
      if (r == n)break;
      appear.reset(nums[l]);
      sum -= nums[l];
    }
    return ans;
  }
};
