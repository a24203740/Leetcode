#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  long long mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<ll> maxPrevScore (n + 1, 0);
    ll maxScore = 0;
    ll maxPrev = 0;
    
    for (int i = 0; i < n; i++) {
      int next = i + questions[i][1] + 1;
      next = min(next, n);
      maxPrev = max(maxPrev, maxPrevScore[i]);
      ll score = questions[i][0] + maxPrev;
      maxPrevScore[next] = max(maxPrevScore[next], score);
      maxScore = max(maxScore, score);
    }
    return maxScore;
  }
};
