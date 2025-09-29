#include "../includes.hpp"

class Solution {
public:
  int largestPerimeter(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    int N = nums.size();
    for(int i = N - 3; i >= 0; i--) {
      for(int j = i + 1; j < N - 1; j++) {
        int lim = nums[i] + nums[j];
        auto it = lower_bound(nums.begin() + j + 1, nums.end(), lim);
        int dis = distance(nums.begin(), it) - 1;
        if(dis > j) {
          bool valid = nums[i] + nums[j] > nums[dis];
          valid &= nums[dis] - nums[j] < nums[i];
          valid &= nums[dis] - nums[i] < nums[j];
          if(valid) return nums[i] + nums[j] + nums[dis];
        }
      }
    }
    return 0; 
  }
};
