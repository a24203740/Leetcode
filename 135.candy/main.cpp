#include "../includes.hpp"

class Solution {
public:
  int candy(vector<int> &ratings) {
    int n = ratings.size();
    int ans = 0;
    vector<int> lowestCandies(n, 1);
    for(int i = 0; i < n; i++) {
      if(i > 0 && ratings[i] > ratings[i - 1]) {
        lowestCandies[i] = lowestCandies[i - 1] + 1;
      }
    }
    for(int i = n - 1; i > 0; i--) {
      if(ratings[i - 1] > ratings[i]) {
        lowestCandies[i - 1] = max(lowestCandies[i - 1], lowestCandies[i] + 1);
      }
      ans += lowestCandies[i];
    }
    return ans + lowestCandies[0];
  }
};
