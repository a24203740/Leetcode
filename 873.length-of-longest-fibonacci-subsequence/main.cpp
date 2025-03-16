#include "../includes.hpp"

class Solution {
public:
  long long int prev2, prev;
  int lenLongestFibSubseq(vector<int> &arr) {
    unordered_map<int, vector<pair<int, int>>> prev;
    size_t n = arr.size();
    int ans = 2;
    for (int i = 1; i < n; i++) {
      auto it = prev.find(arr[i]);
      if (it != prev.end()) {
        for (auto p : it->second) {
          auto it2 = prev.find(arr[i] + p.first);
          if (it2 == prev.end()) {
            prev.emplace(arr[i] + p.first,
                         vector<pair<int, int>>{{arr[i], p.second + 1}});
          } else {
            it2->second.emplace_back(arr[i], p.second + 1);
          }
          ans = max(ans, p.second + 1);
        }
      }

      for (int x = 0; x < i; x++) {
        auto it = prev.find(arr[x] + arr[i]);
        if (it == prev.end()) {
          prev.emplace(arr[x] + arr[i], vector<pair<int, int>>{{arr[i], 2}});
        } else {
          it->second.emplace_back(arr[i], 2);
        }
      }
    }
    if (ans <= 2)
      return 0;
    return ans;
  }
};
