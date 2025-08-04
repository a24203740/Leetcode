#include "../includes.hpp"

class Solution {
public:
  string robotWithString(string s) {
    vector<vector<int>> appear(26);
    auto getNext = [&](int c) {
      for(int i = c+1; i < 26; i++) {
        if(!appear[i].empty()) {
          return i;
        }
      }
      return -1;
    };
    int n = s.size();
    string t; t.reserve(n);
    string ans; ans.reserve(n);
    for(int i = 0; i < n; i++) {
      appear[s[i] - 'a'].push_back(i);
    }
    int smallestChar = getNext(-1);
    int next = appear[smallestChar].back();
    int prev = 0;
    while(smallestChar < 26) {
      if(next >= prev) {
        auto it = lower_bound(appear[smallestChar].begin(), appear[smallestChar].end(), prev);
        int count = distance(it, appear[smallestChar].end());
        while(!t.empty() && t.back() <= (char)(smallestChar + 'a')) {
          ans += t.back();
          t.pop_back();
        }
        for(int i = 0; i < count; i++) {
          ans += (char)(smallestChar + 'a');
        }
        for(int i = prev; i <= next; i++) {
          if(s[i] - 'a' != smallestChar) {
            t += s[i];
          }
        }
        cout << smallestChar << " " << next << " " << prev << endl;
        cout << t << endl;
        prev = next + 1;
      }
      smallestChar = getNext(smallestChar);
      if(smallestChar == -1)break;
      next = appear[smallestChar].back();
    }
    for(auto it = t.rbegin(); it != t.rend(); it++) {
      ans += *it;
    }
    return ans;
  }
};
