#include "../includes.hpp"
#include <bitset>

class Solution {
public:
  int numRabbits(vector<int> &answers) {
    vector<int> appear(1005, 0);
    int ans = 0;
    for(auto x : answers) {
      if(x == 0) {
        ans++;
        continue;
      }
      if(appear[x] == 0) {
        ans += x + 1;
        appear[x] = x;
      }
      else if (appear[x] > 0)appear[x]--;
    }
    return ans;
  }
};
