#include "../includes.hpp"

using ll = long long;
class Solution {
public:
    int emplace_or_increment(unordered_map<int, int>& m, int v) {
      auto it = m.find(v);
      if(it == m.end()) {
        m.emplace(v, 1);
        return 1;
      }
      it->second++;
      return it->second;
    }
    ll comb_2(int x) {
      ll v = x; v *= x-1; v /= 2;
      return v;
    }
    long long countGood(vector<int>& nums, int k) {
      int l = 0, r = 0;
      int n = nums.size();
      unordered_map<int, int> appear;
      ll currentPair = 0;
      ll ans = 0;
      while(r < n) {
        int count = emplace_or_increment(appear, nums[r]);
        r++;
        currentPair -= comb_2(count - 1);
        currentPair += comb_2(count);
        if(currentPair < k)continue;
        while(l < r) {
          auto it = appear.find(nums[l]);
          int minusCount = it->second;
          ll newPair = currentPair - comb_2(minusCount) + comb_2(minusCount - 1);
          if (newPair < k) break;
          currentPair = newPair;
          it->second--;
          l++;
        }
        ans += l + 1;
      }
      return ans;
    }
};
