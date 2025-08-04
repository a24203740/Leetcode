#include "../includes.hpp"

class Solution {
public:
  int longestSubarray(vector<int> &nums) {
    int maxAND = 0;
    int n = nums.size();
    for (int i = 0; i < n; ++i) {
      maxAND = max(maxAND, nums[i]);
    }
    int ans = 0;
    int prev = 0;
    for(int i = 0; i < n; i++) {
      if(nums[i] == maxAND) {
        prev++;
      } else {
        prev = 0;
      }
      ans = max(ans, prev);
    }
    return ans;
  }
};
