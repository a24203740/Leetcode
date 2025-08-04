#include "../includes.hpp"

class Solution {
public:
  string clearStars(string s) {
    int n = s.size();
    int smallest = 5000;
    vector<vector<int>> indexs(26);
    auto getSmallest = [&] (int prevSmallest) -> int {
      if(prevSmallest < 0 || prevSmallest >= 26) {
        prevSmallest = 0;
      }
      if(!indexs[prevSmallest].empty()) {
        return prevSmallest;
      }
      for(int i = prevSmallest; i < 26; i++) {
        if(!indexs[i].empty()) {
          return i;
        }
      }
      return 5000; // No valid character found
    };
    for(int i = 0; i < n; i++) {
      if(s[i] == '*') {
        smallest = getSmallest(smallest);
        int idx = indexs[smallest].back();
        indexs[smallest].pop_back();
        s[idx] = '#';
        s[i] = '#';
      }
      else {
        int idx = s[i] - 'a';
        smallest = min(smallest, idx);
        indexs[idx].push_back(i);
      }
    }
    string ans; ans.reserve(n);
    for(int i = 0; i < n; i++) {
      if(s[i] != '#') {
        ans.push_back(s[i]);
      }
    }
    return ans;
  }
};
