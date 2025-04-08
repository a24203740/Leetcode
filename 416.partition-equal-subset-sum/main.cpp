#include "../includes.hpp"
#include <bitset>

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int n = nums.size();
    bitset<20001> vis{0};
    int tar = 0;
    for (int i : nums) {
      tar += i;
    }
    if(tar % 2 == 1)return false;
    tar /= 2;
    vis.set(0);
    for(int i = 0; i < n; i++) {
      vis = vis | vis >> nums[i];
    }
    return vis[tar];
  }
};
