#include "../includes.hpp"

class Solution {
public:
  int maxDiff(int num) {
    string minimum = to_string(num);
    string maximum = minimum;
    char from = minimum[0], to = '1';
    int it = 0;
    int n = minimum.size();
    if(minimum[0] == '1') {
      while(it < n) {
        if(minimum[it] <= '1') {
          it++;
        }
        else break;
      }
      if(it == n) to = '1';
      else {
        from = minimum[it];
        to = '0';
      }
    }
    for(int i = 0; i < n; i++) {
      if(minimum[i] == from) minimum[i] = to;
    }
    from = maximum[0];
    to = '9';
    it = 0;
    if(maximum[0] == '9') {
      while(it < n) {
        if(maximum[it] == '9') {
          it++;
        }
        else break;
      }
      if(it != n)from = maximum[it];
    }
    for(int i = 0; i < n; i++) {
      if(maximum[i] == from) maximum[i] = to;
    }
    return stoi(maximum) - stoi(minimum);
  }
};
