#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  int numSubseq(vector<int> &nums, int target) {
    const int mod = 1e9 + 7;
    auto fastPow = [&mod](ll base, ll exp) {
      ll res = 1;
      while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
      }
      return res;
    };
    sort(nums.begin(), nums.end());
    ll ans = 0;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
      int find = target - nums[i] + 1;
      auto it = lower_bound(nums.begin(), nums.end(), find);
      auto dis = distance(nums.begin(), it);
      int count = dis - i - 1;
      if(count < 0) break;
      if(count == 0) ans++;
      else ans = (ans + fastPow(2, count)) % mod;
    }
    return ans;
  }
};
