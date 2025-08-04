#include "../includes.hpp"

class Solution {
public:
  int maxSum(vector<int> &nums) { 
    int maxVal = -50000;
    bitset<105> appear{0};
    int n = nums.size();
    int sum = 0;
    bool select = false;
    for(int i = 0; i < n; i++) {
      maxVal = max(maxVal, nums[i]);
      if(nums[i] < 0) continue;
      if(appear.test(nums[i])) continue;
      appear.set(nums[i]);
      sum += nums[i];
      select = true;
    }
    if(!select) {
      return maxVal;
    }
    return sum;
  }
};
