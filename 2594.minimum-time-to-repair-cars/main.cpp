#include "../includes.hpp"
#include <cmath>

using ll = long long;
class Solution {
public:
  bool canRepair(vector<int> &ranks, int cars, ll time) {
    int n = ranks.size();
    for (int i = 0; i < n; i++) {
      double lefttime = static_cast<double>(time) / ranks[i];
      ll maxPossibleCar = floor(sqrt(lefttime));
      cars -= maxPossibleCar;
      if (cars <= 0) {
        return true;
      }
    }
    return false;
  }
  ll findMaxTime(vector<int> &ranks, int cars) {
    int maxRank = 0;
    for (int i = 0; i < ranks.size(); i++) {
      maxRank = max(maxRank, ranks[i]);
    }
    return static_cast<ll>(maxRank) * static_cast<ll>(cars) * static_cast<ll>(cars);
  }
  ll repairCars(vector<int> &ranks, int cars) {
    ll l = 0, r = findMaxTime(ranks, cars);
    while (l < r) {
      ll m = l + (r - l) / 2;
      if (canRepair(ranks, cars, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
