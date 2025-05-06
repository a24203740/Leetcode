#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  long long countInterestingSubarrays(vector<int> &nums, int modulo, int k) {
    int n = nums.size();
    int tableSize = min(n+5, modulo+5);
    vector<int> table(tableSize, 0);
    table[0] = 1;
    int prefix = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      if(nums[i] % modulo == k) {
        prefix++;
      }
      int mod = prefix % modulo;
      if(mod >= k)ans += table[mod - k];
      else if(modulo <= n)ans += table[mod + modulo - k];
      table[mod]++;
    }
    return ans;
  }
};
