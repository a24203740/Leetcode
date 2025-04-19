#include "../includes.hpp"
#include <iterator>

using ll = long long;
class Solution {
public:
  long long countFairPairs(vector<int> &nums, int lower, int upper) {
    ll ans = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    int mn = nums[0], mx = nums[n - 1];
    for(int i = 0; i < n; i++) {
      int lb = lower - nums[i];
      int rb = upper - nums[i];
      if(lb > mx || rb < mn) {
        continue;
      }
      auto lbit = lower_bound(nums.begin(), nums.end(), lb);
      auto rbit = upper_bound(nums.begin(), nums.end(), rb);
      int lbindex = distance(nums.begin(), lbit);
      int rbindex = distance(nums.begin(), rbit);
      if (rbit != nums.end() && *rbit == rb) {
        rbindex++;
      }
      ans += rbindex - lbindex;
      if (i >= lbindex && i < rbindex) {
        ans--;
      }
    }
    return ans;
  }
};
