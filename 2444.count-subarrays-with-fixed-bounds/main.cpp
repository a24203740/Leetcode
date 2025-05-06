#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  ll countSubSubArr(const vector<int>& nums, int l, int r, int mn, int mx)  {
    if(l > r) return 0;
    int mnAppear = -1, mxAppear = -1;
    int st = l;
    ll res = 0;
    for(int i = l; i <= r; ++i) {
      if(nums[i] == mn)mnAppear = i;
      if(nums[i] == mx)mxAppear = i;
      if(mnAppear != -1 && mxAppear != -1) {
        res += static_cast<ll>(r - max(mnAppear, mxAppear) + 1) * (min(mnAppear, mxAppear) - st + 1);
        st = min(mnAppear, mxAppear) + 1;
        if(mnAppear < st)mnAppear = -1;
        if(mxAppear < st)mxAppear = -1;
      }
    }
    return res;
  }
  long long countSubarrays(vector<int> &nums, int minK, int maxK) {
    int n = nums.size();
    int l = 0;
    ll ans = 0;
    for(int i = 0; i < n; i++) {
      if(nums[i] < minK || nums[i] > maxK) {
        ans += countSubSubArr(nums, l, i - 1, minK, maxK);
        l = i + 1;
      }
    }
    ans += countSubSubArr(nums, l, n - 1, minK, maxK);
    return ans;
  }
};
