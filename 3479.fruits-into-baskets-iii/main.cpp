#include "../includes.hpp"
#include <cmath>

class Solution {
public:
  int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets) {
    int n = fruits.size();
    int m = sqrt(n);
    int section = n / m + (n % m == 0 ? 0 : 1);
    vector<int> maxOfSection(section, 0);
    for(int i = 0; i < n; i++) {
      int s = i / m;
      maxOfSection[s] = max(maxOfSection[s], baskets[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
      int f = fruits[i];
      bool placed = false;
      for(int s = 0; s < section; s++) {
        if(maxOfSection[s] < f) {
          continue;
        }
        maxOfSection[s] = 0;
        int l = s * m;
        int r = min((s + 1) * m, n);
        for(int x = l; x < r; x++) {
          if (!placed && baskets[x] >= f) {
            baskets[x] = 0;
            placed = true;
          }
          maxOfSection[s] = max(maxOfSection[s], baskets[x]);
        }
        break;
      }
      if(!placed) {
        ans++;
      }
    }
    return ans;
  }
};
