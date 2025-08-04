#include "../includes.hpp"

class Solution {
public:
  int direction(const string& s, int k, char hReplace, char vReplace) {
    int n = s.size();
    int ans = 0, counter = 0;
    for(int i = 0; i < n; i++) {
      if(s[i] == hReplace || s[i] == vReplace) {
        if(k <= 0) counter--;
        else {
          counter++;
          k--;
        }
      } else counter++;
      ans = max(ans, counter);
    }
    return ans;
  }
  int maxDistance(string s, int k) {
    int ans = direction(s, k, 'E', 'N');
    ans = max(ans, direction(s, k, 'W', 'N'));
    ans = max(ans, direction(s, k, 'E', 'S'));
    ans = max(ans, direction(s, k, 'W', 'S'));
    return ans;
  }
};
