#include "../includes.hpp"

class Solution {
public:
  int check(vector<int>& nums, int lim, int p) {
    int n = nums.size();
    int count = 0;
    int mx = 0;
    for(int i = 0; i < n - 1; i++) {
      if(abs(nums[i] - nums[i+1]) <= lim) {
        mx = max(mx, abs(nums[i] - nums[i+1]));
        count++;
        i++;
      }
      if(count >= p) {
        return mx;
      }
    }
    return -1;
  }
  int minimizeMax(vector<int> &nums, int p) {
    if(p == 0) {
      return 0;
    }
    sort(nums.begin(), nums.end());
    int l = 0, r = 0;
    for(auto &x : nums) {
      r = max(r, x);
    }
    while(l < r) {
      int mid = (l + r) / 2;
      int res = check(nums, mid, p);
      if(res != -1) {
        r = res;
      } else {
        l = mid + 1;
      }
    }
    return r;
  }
};
