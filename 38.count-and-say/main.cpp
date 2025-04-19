#include "../includes.hpp"
#include <string>

class Solution {
public:
  string countAndSay(int n) {
    if(n == 1) return "1";
    else {
      string prev = countAndSay(n - 1);
      string res = "";
      char prevNum = prev[0];
      int count = 0;
      for(auto c : prev) {
        if(c == prevNum) {
          count++;
        } else {
          res += to_string(count);
          res += prevNum;
          prevNum = c;
          count = 1;
        }
      }
      res += to_string(count);
      res += prevNum;
      return res;
    }
  }
};

