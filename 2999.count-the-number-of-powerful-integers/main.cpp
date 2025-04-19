#include "../includes.hpp"

#include <cmath>
using ll = long long;
class Solution {
public:
  ll count (int limit, string s, string ed) {
    if (ed.size() < s.size()) {
      return 0;
    }
    if (ed.size() == s.size()) {
      if (s > ed) {
        return 0;
      }
      else return 1;
    }
    int prefixlen = ed.size() - s.size();
    string suffix = ed.substr(prefixlen);
    ll ans = 0;
    for(int pos = 0; pos < prefixlen; pos++) {
      int rightDigit = prefixlen - pos - 1;
      if(ed[pos] - '0' > limit) {
        ans += (ll)pow(limit + 1, rightDigit + 1);
        return ans;
      }
      ans += (ll)(ed[pos] - '0') * (ll)pow(limit + 1, rightDigit);
    }
    if(suffix >= s) {
      ans++;
    }
    return ans;
  }
  long long numberOfPowerfulInt(long long start, long long finish, int limit,
                                string s) {
    string left = to_string(start - 1);
    string right = to_string(finish);
    return count(limit, s, right) - count(limit, s, left);
  }
};
