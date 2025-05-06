#include "../includes.hpp"

class Solution {
public:
  vector<int> buildArray(vector<int> &nums) {
    vector<int> tp(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
      tp[i] = nums[nums[i]];
    }
    return tp;
  }
};
