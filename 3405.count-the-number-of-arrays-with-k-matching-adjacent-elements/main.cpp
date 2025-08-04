#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  int extgcd(int a, int b, int &x, int &y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1, a1 = a, b1 = b;
    while (b1) {
      int q = a1 / b1;
      tie(x, x1) = make_tuple(x1, x - q * x1);
      tie(y, y1) = make_tuple(y1, y - q * y1);
      tie(a1, b1) = make_tuple(b1, a1 - q * b1);
    }
    return a1;
  }
  int modInv(int v, int m) {
    int x, y;
    int g = extgcd(v, m, x, y);
    if (g != 1) return -1;
    return (x % m + m) % m;
  }
  int C(int a, int b) {
    ll bottom = 1, top = 1;
    for (int i = 0; i < b; ++i) {
      top = top * (a - i) % mod;
      bottom = bottom * (i + 1) % mod;
    }
    ll inv = modInv(bottom, mod);
    ll res = (top * inv) % mod;
    return res;
  }
  const int mod = 1e9 + 7;
  int countGoodArrays(int n, int m, int k) {
    ll comb = C(n - 1, k);
    ll differenet = m;
    int differentCount = n - 1 - k;
    while (differentCount--) {
      differenet = (differenet * (m - 1)) % mod;
    }
    return (comb * differenet) % mod;
  }
};
