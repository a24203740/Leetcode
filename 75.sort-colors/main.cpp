#include "../includes.hpp"

class Solution {
public:
  void sortColors(vector<int> &nums) {
    array<int, 3> color = {0, 0, 0};
    for(auto c : nums) {
      color[c]++;
    }
    int it = 0;
    for(int i = 0; i < 3; i++) {
      int n = color[i];
      while(n--) {
        nums[it++] = i;
      }
    }
  }
};
