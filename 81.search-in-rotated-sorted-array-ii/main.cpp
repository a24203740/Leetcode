#include "../includes.hpp"
#include <algorithm>

class Solution {
public:
  bool search(vector<int> &nums, int target) {
    int n = nums.size();
    int l = 0, r = n - 1;
    int rotatePivot = 0;
    if(n == 1)return nums[0] == target;
    int solid = 0;
    if(nums[0] == nums[n-1]) {
      if(nums[0] == target) {
        return true;
      }
      while(solid < n && nums[solid] == nums[0]) {
        solid++;
      }
    }
    if(solid == n) {
      return false;
    }
    if (nums[n-1] > nums[solid]) {
      auto it = (lower_bound(nums.begin() + solid, nums.end(), target));
      if (it != nums.end() && *it == target) {
        return true;
      }
      return false;
    }
    l = solid;
    while (l <= r) {
      int m = (l + r) / 2;
      cout << l << " " << m << " " << r << endl;
      if(nums[m] >= nums[solid]) {
        if (m + 1 < n && nums[m + 1] < nums[m]) {
          rotatePivot = m + 1;
          break;
        }
        else l = m + 1;
      }
      else r = m - 1;
    }
    cout << rotatePivot << endl;
    vector<int>::iterator left, right;
    if(target >= nums[solid]) {
      left = nums.begin() + solid;
      right = nums.begin() + rotatePivot;
    }
    else {
      left = nums.begin() + rotatePivot;
      right = nums.end();
    }
    auto it = lower_bound(left, right, target);
    if (it != right && *it == target) {
      return true;
    }
    return false;
  }
};
