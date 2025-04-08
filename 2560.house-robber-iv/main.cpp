#include "../includes.hpp"

class Solution {
public:
  bool canSatisfy(vector<int> &nums, int k, int threshold) {
    bool prev = false;
    for (auto x : nums) {
      if(prev)prev = false;
      else if(x <= threshold){
        k--; prev = true;
        if(k <= 0)return true;
      }
    }
    return false;
  }
  int minCapability(vector<int> &nums, int k) {
    int maxNum = 0;
    for (auto x : nums) {
      maxNum = max(maxNum, x);
    }
    int l = 0, r = maxNum;
    while (l < r) {
      int mid = l + (r - l) / 2;
      if (canSatisfy(nums, k, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    return l;
  }
};
