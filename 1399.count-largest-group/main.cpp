#include "../includes.hpp"

class Solution {
public:
  int countDigit(int n) {
    int x = 0; 
    while(n > 0) {
      x += n%10;
      n/=10;
    }
    return x;
  }
  int countLargestGroup(int n) {
    vector<int> group(40, 0);
    int mx = 0;
    for(int i = 1; i <= n; i++) {
      int x = countDigit(i);
      group[x]++;
      mx = max(mx, group[x]);
    }
    int ans = 0;
    for(auto g: group) {
      if(g == mx) ans++;
    }
    return ans;
  }
};
