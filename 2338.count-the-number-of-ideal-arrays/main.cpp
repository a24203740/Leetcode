#include "../includes.hpp"

using ll = long long;
const ll MOD = 1e9 + 7;
class Solution {
public:
  vector<int> primes;
  vector<ll> factorial;
  vector<ll> inverseFactorial;
  ll extgcd(ll a, ll b, ll &x, ll &y) {
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
  void buildFactorial(int n) {
    factorial.resize(n + 1);
    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
      factorial[i] = (factorial[i - 1] * i) % MOD;
      // cout << "factorial[" << i << "] = " << factorial[i] << endl;
    }
  } void buildInverseFactorial(int n) {
    inverseFactorial.resize(n + 1);
    ll v = 1;
    for (int i = 0; i <= n; ++i) {
      inverseFactorial[i] = v;
      v = v * factorial[i] % MOD;
    }
    ll x, y;
    extgcd(v, MOD, x, y);
    x = (x % MOD + MOD) % MOD;
    for (int i = n; i >= 0; --i) {
      inverseFactorial[i] = x * inverseFactorial[i] % MOD;
      // cout << "invfactorial[" << i << "] = " << inverseFactorial[i] << endl;
      x = x * factorial[i] % MOD;
    }
  }
  void constructPrimeTable() {
    vector<bool> isPrime(10005, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i < 10005; i++) {
      if (isPrime[i]) {
        primes.push_back(i);
        for (int j = 2 * i; j < 10005; j += i) {
          isPrime[j] = false;
        }
      }
    }
  }
  ll C(ll n, ll m) {
    if (n < m)
      return 0;
    // cout << "C(" << n << "," << m << ")" << endl;
    // cout << factorial[n] << " " << inverseFactorial[m] << " "
    //      << inverseFactorial[n - m] << endl;
    return ((factorial[n] * inverseFactorial[m] % MOD) *
            inverseFactorial[n - m] % MOD);
  }
  ll divideNtoMheap(ll n, ll m) {
    // cout << n << " to " << m << " heap" << endl;
    ll from = n + m - 1, choose = m - 1;
    return C(from, choose);
  }
  int idealArrays(int n, int maxValue) {
    ll ans = 0;
    // arrayWithProductCount[i] = how many array (length n) have all element
    // product i
    vector<ll> arrayWithProductCount(10005, 0);
    constructPrimeTable();
    buildFactorial(10015);
    buildInverseFactorial(10015);
    arrayWithProductCount[1] = 1;
    for (int i = 2; i <= maxValue; i++) {
      vector<pair<int, int>> primeFactors;
      int tp = i;
      // cout << "product " << i << endl;
      for (auto prime : primes) {
        if (tp <= 1)
          break;
        if (tp % prime == 0) {
          int count = 0;
          while (tp % prime == 0) {
            tp /= prime;
            count++;
          }
          primeFactors.push_back({prime, count});
        }
      }
      ll res = 1;
      for (auto p : primeFactors) {
        // cout << "primeFactor " << p.first << endl;
        res = (res * divideNtoMheap(p.second, n-1)) % MOD;
      }
      arrayWithProductCount[i] = res;
      // cout << res << endl;
    }
    for (int i = 1; i <= maxValue; i++) {
      // cout << "i: " << arrayWithProductCount[i] << endl;
      arrayWithProductCount[i] += arrayWithProductCount[i - 1];
      arrayWithProductCount[i] %= MOD;
    }
    for (int i = 1; i <= maxValue; i++) {
      int highestPossibleProduct = maxValue / i;
      // cout << "start with " << i << " has " << arrayWithProductCount[highestPossibleProduct] << endl;
      ans += arrayWithProductCount[highestPossibleProduct];
      ans %= MOD;
    }
    return ans;
  }
};
