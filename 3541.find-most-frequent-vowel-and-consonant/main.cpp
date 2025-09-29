#include "../includes.hpp"

class Solution {
public:
  int maxFreqSum(string s) {
    array<int, 26> count = {0};
    int maxNotVowel = 0;
    int maxVowel = 0;
    for (char c : s) {
      count[c - 'a']++;
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        maxVowel = max(maxVowel, count[c - 'a']);
      } else {
        maxNotVowel = max(maxNotVowel, count[c - 'a']);
      }
    }
    return maxVowel + maxNotVowel;
  }
};
