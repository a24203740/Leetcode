#include "../includes.hpp"
#include <cmath>
#include <unordered_set>

using ll = long long;
class Solution {
public:
  string padding(ll x, size_t n) {
    auto str = to_string(x);
    auto newStr = string(n - min(n, str.size()), '0') + str;
    return std::move(newStr);
  }
  long long countGoodIntegers(int n, int k) {
    int half = n / 2;
    bool odd = false;
    if (n % 2 == 1) {
      odd = true;
      half++;
    }
    int lim = pow(10, half);
    unordered_set<string> candidates;
    for (int i = 0; i <= lim; i++) {
      if (i % 10 == 0)
        continue;
      ll suf = i;
      string preStr = padding(i, half);
      reverse(preStr.begin(), preStr.end());
      ll pre = stoll(preStr);
      if (odd)
        pre /= 10;
      ll total = suf + pre * lim;
      if (total % k == 0) {
        auto s = to_string(total);
        sort(s.begin(), s.end());
        candidates.insert(s);
      }
    }
    ll ans = 0;
    ll permutations[11];
    for (int i = 0; i < 11; i++) {
      permutations[i] = 1;
    }
    for (int i = 2; i < 11; i++) {
      permutations[i] = permutations[i - 1] * i;
      cout << i << " " << permutations[i] << endl;
    }
    for (const auto &c : candidates) {
      vector<int> count(10, 0);
      for (int i = 0; i < n; i++)
        count[c[i] - '0']++;
      ll total = permutations[n-1];
      total *= (n - count[0]);
      for (int i = 0; i < 10; i++) {
        total /= permutations[count[i]];
      }
      ans += total;
    }
    return ans;
  }
};
