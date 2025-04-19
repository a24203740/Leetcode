#include "../includes.hpp"

using ll = long long;
const ll MOD = 1e9+7;
class Solution {
public:
  ll fastpow(ll x, ll p) {
    ll one = 1;
    int now = 0;
    ll base = 1;
    ll res = 1;
    for(now = 0; (one << now) <= p; now++) {
      if (base == 1) base = x;
      else base = (base * base) % MOD;
      if (p & (one << now)) {
        res = (res * base) % MOD;
      }
    }
    return res;
  }
  int countGoodNumbers(long long n) {
    ll ans = 1;
    ll odd = n / 2, even = n / 2;
    if (n % 2 == 1) {
      even++;
    }
    return fastpow(5, even) * fastpow(4, odd) % MOD;
  }
};
