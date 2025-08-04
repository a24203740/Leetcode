#include "../includes.hpp"

class Solution {
public:
  int partitionArray(vector<int> &nums, int k) {
    sort(nums.begin(), nums.end());
    int curVal = nums[0], ans = 1;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
      if(nums[i] - curVal > k) {
        ans++;
        curVal = nums[i];
      }
    }
    return ans;
  }
};
