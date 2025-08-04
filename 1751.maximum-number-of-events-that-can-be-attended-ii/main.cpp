#include "../includes.hpp"

using pii = pair<int, int>;
class Solution {
public:
  int maxValue(vector<vector<int>> &events, int k) {
    int n = events.size();
    vector<int> startTime(n);
    vector<vector<int>> dp(n+1, vector<int>(k+1, 0));
    sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
      return a[0] < b[0];
    });
    for(int i = 0; i < n; i++) {
      startTime[i] = events[i][0];
    }
    vector<int> maxValue(k + 1, 0);
    for(int i = 0; i < n; i++) {
      for(int x = 0; x <= k; x++) {
        maxValue[x] = max(maxValue[x], dp[i][x]);
      }
      int end = events[i][1];
      auto it = lower_bound(startTime.begin(), startTime.end(), end + 1);
      int idx = distance(startTime.begin(), it); // the first event that can be attended if this event is attended
      for(int x = 0; x < k; x++) {
        dp[idx][x+1] = max(dp[idx][x+1], maxValue[x] + events[i][2]);
      }
    }
    int ans = 0;
    for(int i = 0; i <= k; i++) {
      maxValue[i] = max(maxValue[i], dp[n][i]);
      ans = max(ans, maxValue[i]);
    }
    return ans;
  }
};
