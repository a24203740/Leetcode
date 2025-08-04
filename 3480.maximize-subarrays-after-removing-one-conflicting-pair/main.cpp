#include "../includes.hpp"

const int MAX = 1e6;
class Solution {
public:
  long long maxSubarrays(int n, vector<vector<int>> &conflictingPairs) {
    vector<int> endIndex(n+5, n);
    vector<int> subendIndex(n+5, n);
    for(int i = 0; i < conflictingPairs.size(); i++) {
      if (conflictingPairs[i][0] > conflictingPairs[i][1]) {
        swap(conflictingPairs[i][0], conflictingPairs[i][1]);
      }
    }
    sort(conflictingPairs.begin(), conflictingPairs.end(), [](const vector<int>& a, const vector<int>& b) {
      return a[1] > b[1];
    });
    for(const auto& p: conflictingPairs) {
      int st = p[0] - 1, ed = p[1] - 1;
      if(st > ed) {
        swap(st, ed);
      }
      if(endIndex[st] >= ed) {
        subendIndex[st] = endIndex[st];
        endIndex[st] = ed;
      }
    }
    int wallPos = n+5, wallVal = MAX, secondWallVal = MAX;
    long long ans = 0, maxGain = 0, gain = 0;
    for(int i = n-1; i >= 0; i--) {
      if(wallVal >= endIndex[i]) {
        secondWallVal = min(secondWallVal, wallVal);
        secondWallVal = min(secondWallVal, subendIndex[i]);
        wallVal = endIndex[i];
        wallPos = i;
        gain = 0;
      }
      else {
        secondWallVal = min(secondWallVal, endIndex[i]);
      }
      ans += wallVal - i;
      gain += min(secondWallVal, subendIndex[wallPos]) - wallVal;
      maxGain = max(maxGain, gain);
    }
    return ans + maxGain;
  }
};
