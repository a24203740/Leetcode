#include "../includes.hpp"

class Solution {
public:
  int maxDifference(string s) {
    int oMx = -1, eMn = 1e9;
    int n = s.size();
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
      cnt[s[i] - 'a']++;
    }
    for(int i = 0; i < 26; i++) {
      if(cnt[i] == 0) continue;
      if(cnt[i] % 2 == 0) {
        eMn = min(eMn, cnt[i]);
      } else {
        oMx = max(oMx, cnt[i]);
      }
    }
    return oMx - eMn;
  }
};
