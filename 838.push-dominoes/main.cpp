#include "../includes.hpp"

class Solution {
public:
  string pushDominoes(string dominoes) {
    bool loose = false;
    do {
      loose = false;
      char prevDominoe = '.';
      int n = dominoes.size();
      for(int i = 0; i < n; i++) {
        char tpPrev = dominoes[i];
        if(dominoes[i] != '.') {
          prevDominoe = tpPrev;
          continue;
        }
        bool left = prevDominoe == 'R';
        bool right = (i != n-1 && dominoes[i+1] == 'L');
        if(left && right) {
          prevDominoe = tpPrev;
          continue;
        } else if(left) {
          dominoes[i] = 'R';
          loose = true;
        } else if(right) {
          dominoes[i] = 'L';
          loose = true;
        }
        prevDominoe = tpPrev;
      }
    }while(loose);
    return dominoes;
  }
};
