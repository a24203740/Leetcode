#include "../includes.hpp"
#include <cstring>

using ll = long long;
class Solution {
public:
  const int m = 1e9 + 7;
  int countBalancedPermutations(string num) {
    int n = num.size();
    vector<int> appear(10, 0);
    vector<pair<int, int>> prefix(10, {0, 0});
    int sum = 0;
    for (auto c : num) {
      appear[c - '0']++;
      sum += c - '0';
    }
    prefix[0] = {0, appear[0]};
    for (int i = 1; i < 10; i++) {
      prefix[i].first = appear[i] * i + prefix[i - 1].first;
      prefix[i].second = appear[i] + prefix[i - 1].second;
    }
    int oddTargetCount = num.size() / 2;
    int evenTargetCount = n - oddTargetCount;
    int target = sum / 2;
    if (sum % 2 != 0) {
      return 0;
    }
    array<array<ll, 45>, 45> comb;
    comb[0][0] = 1;
    for(int i = 1; i < 45; i++){
      comb[i][0] = comb[i][i] = 1;
      for(int j = 1; j < i; j++) {
        comb[i][j] = (comb[i - 1][j - 1] + comb[i - 1][j]) % m;
      }
    }
    array<array<ll, 361>, 361> dp;
    dp.fill({0});
    dp[0][0] = 1;
    for(int i = 0; i < 10; i++) {
      int prefixSum = prefix[i].first;
      int prefixCount = prefix[i].second;
      int oddCountUpper = min(prefixCount, oddTargetCount);
      int oddCountLower = max(0, prefixCount - evenTargetCount);
      for(int oddCount = oddCountUpper; oddCount >= oddCountLower; oddCount--) {
        int evenCount = prefixCount - oddCount;
        int oddSumUpper = min(prefixSum, target);
        int oddSumLower = max(0, prefixSum - target);
        for (int oddSum = oddSumUpper; oddSum >= oddSumLower; oddSum--) {
          int newCountUpper = min(appear[i], oddCount);
          int newCountLower = max(0, appear[i] - evenCount);
          ll res = 0;
          for(int newCount = newCountLower; newCount <= newCountUpper; newCount++) {
            if(i * newCount > oddSum) {
              break;
            }
            // combination of choosing newCount position from oddCount postiion for placing i
            // also choose appear - newCount position from evenCount position for placing i
            ll placingIPossibilties = comb[oddCount][newCount] * comb[evenCount][appear[i] - newCount] % m;
            res += placingIPossibilties * dp[oddCount - newCount][oddSum - newCount * i];
            res %= m;
          }
          dp[oddCount][oddSum] = res;
        }
      }
    }
    return dp[oddTargetCount][target] % m;
  }
};
