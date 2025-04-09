#include "../includes.hpp"

class Solution {
public:
  int minOperations(vector<int> &nums, int k) {
    bitset<101> vis{0};
    int ans = 0;
    for(auto x : nums) {
      if(x < k) return -1;
      else if(x > k) {
        if(vis[x]) continue;
        vis[x] = 1;
        ans++;
      }
    }
    return ans;
  }
};
