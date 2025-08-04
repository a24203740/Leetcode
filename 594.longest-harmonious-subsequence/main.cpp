#include "../includes.hpp"

class Solution {
public:
  int findLHS(vector<int> &nums) {
    map<int, int> count;
    for(auto &num : nums) {
      auto it = count.find(num);
      if(it == count.end()) {
        it = count.emplace(num, 0).first;
      }
      it->second += 1;
    }
    int ans = 0;
    for(auto [idx, c] : count) {
      auto it = count.find(idx + 1);
      auto it2 = count.find(idx - 1);
      int c1 = 0, c2 = 0;
      if(it != count.end()) c1 = it->second;
      if(it2 != count.end()) c2 = it2->second;
      if(c1 == 0 && c2 == 0) continue;
      ans = max(ans, c + max(c1, c2));
    }
    return ans;
  }
};
