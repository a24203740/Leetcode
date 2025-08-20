#include "../includes.hpp"
#include <bitset>

class Solution {
public:
  const unsigned long long MOD = 1e9 + 7;
  vector<int> productQueries(int n, vector<vector<int>> &queries) {
    bitset<32> bit{static_cast<unsigned long long>(n)};
    vector<unsigned long long> powers;
    for (int i = 0; i < 31; ++i) {
      if (bit[i]) {
        powers.push_back(1UL << i);
      }
    }
    vector<int> ans;
    ans.reserve(queries.size());
    for(const auto &query : queries) {
      unsigned long long product = 1;
      for (int i = query[0]; i <= query[1]; ++i) {
        product = (product * powers[i]) % MOD;
      }
      ans.push_back(static_cast<int>(product));
    }
    return ans;
  }
};
