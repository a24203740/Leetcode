#include "../includes.hpp"

class Solution {
public:
  bool doesAliceWin(string s) {
    int n = s.size();
    for (int i = 0; i < n; i++) {
      if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        return true;
      }
    }
    // odd number start: alice remove all, bob lose
    // even (>2) number start: alice remove one (remain -> odd), bob remove any number (remain == odd), alice remove all.
    return false;
  }
};
