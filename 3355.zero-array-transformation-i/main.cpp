#include "../includes.hpp"

class Solution {
public:
  bool isZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> add(n, 0), sub(n, 0);
    for(const auto& q: queries) {
      add[q[1]]++;
      sub[q[0]]++;
    }
    int walker = 0;
    for(int i = 0; i < n; i++) {
      walker += sub[i];
      if(nums[i] > walker) return false;
      walker -= add[i];
    }
    return true;
  }
};
