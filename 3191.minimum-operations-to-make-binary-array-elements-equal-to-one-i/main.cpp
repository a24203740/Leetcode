#include "../includes.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n - 2; i++) {
      if (nums[i] == 0) {
        ans++;
        nums[i + 1] = !nums[i + 1];
        nums[i + 2] = !nums[i + 2];
      }
    }
    if(nums[n - 2] == 0 || nums[n - 1] == 0) return -1;
    return ans;
  }
};
