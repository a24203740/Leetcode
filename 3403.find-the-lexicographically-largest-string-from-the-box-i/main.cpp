#include "../includes.hpp"
#include <string_view>

bool smaller(const string_view& a, const string_view& b) {
  int lim = min(a.size(), b.size());
  for(int i = 0 ; i < lim ; i++) {
    if(a[i] != b[i]) {
      return a[i] < b[i];
    }
  }
  return a.size() < b.size();
}

class Solution {
public:
  string answerString(string word, int numFriends) {
    if(numFriends <= 1) {
      return word;
    }
    size_t longest = word.size() - (numFriends - 1);
    string_view wordView(word);
    string_view ans = wordView.substr(0, longest);
    for(size_t i = 1; i < word.size() ; i++) {
      int len = min(longest, word.size() - i);
      string_view current = wordView.substr(i, len);
       if(smaller(ans, current)) {
         ans = current;
       }
    }
    return string(ans);
  }
};
