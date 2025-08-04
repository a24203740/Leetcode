#include "../includes.hpp"

class Solution {
public:
  char kthCharacter(int k) {
    string s = "a";
    while(s.size() < k) {
      int n = s.size();
      for(int i = 0; i < n; i++) {
        char next = s[i];
        if(next == 'z') {
          next = 'a';
        } else {
          next++;
        }
        s += next;
      }
    }
    return s[k - 1];
  }
};
