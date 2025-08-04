#include "../includes.hpp"

class Solution {
public:
  int maxOR;
  int ans;
  void DFS(int i, int currentOR, const vector<int> &nums) {
    int newOR = currentOR | nums[i];
    if (newOR == maxOR) {
      ans += (1 << (nums.size() - i - 1));
    }
    if(i == nums.size() - 1) {
      return;
    }
    if(newOR != maxOR) {
      DFS(i + 1, newOR, nums);
    }
    DFS(i + 1, currentOR, nums);
  }
  int countMaxOrSubsets(vector<int> &nums) {
    maxOR = 0;
    ans = 0;
    for (auto x : nums) {
      maxOR |= x;
    }
    DFS(0, 0, nums);
    return ans;
  }
};
