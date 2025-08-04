#include "../includes.hpp"
#include <cctype>

class Solution {
public:
  bool isValid(string word) {
    bool vowel = false, consonant = false;
    if (word.size() < 3) return false;
    for(auto c : word) {
      if(!isalnum(c)) return false;
      if(isupper(c)) c = tolower(c);
      if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        vowel = true;
      } else if(isalpha(c)) {
        consonant = true;
      }
    }
    return vowel && consonant;
  }
};
