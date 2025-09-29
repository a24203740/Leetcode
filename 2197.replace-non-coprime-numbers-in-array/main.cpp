#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  int GCDwrapper(int a, int b) {
    if (a < b) swap(a, b);
    return GCD(a, b);
  }
  int GCD(int a, int b) {
    if (b == 0) return a;
    return GCD(b, a % b);
  }
  vector<int> replaceNonCoprimes(vector<int> &nums) {
    vector<int> stack;
    int n = nums.size();
    stack.reserve(n);
    stack.push_back(nums[0]);
    for(int i = 1; i < n; i++) {
      int cur = nums[i];
      while (!stack.empty()) {
        int top = stack.back();
        int gcd = GCDwrapper(cur, top);
        if (gcd != 1) {
          ll tp = static_cast<ll>(cur) * top;
          tp /= gcd;
          cur = tp;
          stack.pop_back();
        }
        else break;
      }
      stack.push_back(cur);
    }
    return stack;
  }
};
