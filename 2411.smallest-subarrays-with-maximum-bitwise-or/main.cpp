#include "../includes.hpp"

class Solution {
public:
  vector<int> smallestSubarrays(vector<int> &nums) {
    vector<vector<int>> bitPosition(64);
    auto extractBits = [&](int num, int pos) {
      for (int i = 0; i < 32; ++i) {
        if (num & (1LL << i)) {
          bitPosition[i].push_back(pos);
        }
      }
    };
    int maxOR = 0;
    int n = nums.size();
    for (int i = 0; i < nums.size(); ++i) {
      extractBits(nums[i], i);
    } 
    vector<int> ans(n, 0);
    for(int i = n-1; i >= 0; i--) {
      maxOR |= nums[i];
      int minL = i;
      for(int j = 0; j < 32; j++) {
        if( maxOR & (1LL << j) ) {
          int tn = bitPosition[j].size();
          if(tn >= 2 && bitPosition[j][tn-2] >= i) {
            bitPosition[j].pop_back();
          }
          int val = bitPosition[j].back();
          minL = max(minL, val);
        }
      }
      ans[i] = minL - i + 1;
    }
    return ans;
  }
};
