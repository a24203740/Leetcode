#include "../includes.hpp"

class Solution {
public:
  string makeFancyString(string s) {
    if(s.size() < 3) return s;
    bool prevSame = s[0] == s[1];
    string ans = ""; ans += s[0]; ans += s[1];
    for(int i = 2; i < s.size(); i++) {
      if(s[i] == s[i-1]) {
        if(prevSame) {
          prevSame = true;
          continue;
        }
        prevSame = true;
      }
      else prevSame = false;
      ans += s[i];
    }
    return ans;
  }
};
