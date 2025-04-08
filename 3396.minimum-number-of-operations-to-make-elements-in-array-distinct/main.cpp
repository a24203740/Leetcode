#include "../includes.hpp"
#include <bitset>

class Solution {
public:
  int minimumOperations(vector<int> &nums) { 
    bitset<101> vis{0};
    int n = nums.size();
    int i;
    bool dup = false;
    for(i = n-1; i >= 0; i--) {
      if(!vis[nums[i]]) {
        vis[nums[i]] = 1;
      } else {
        dup = true;
        break;
      }
    }
    if(!dup) {
      return 0;
    }
    return (i / 3) + 1;
  }
};
