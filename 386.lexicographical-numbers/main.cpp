#include "../includes.hpp"

class Solution {
public:
  vector<int> lexicalOrder(int n) {
    vector<int> ans;
    int cur = 0;
    while (ans.size() < n) {
      cur++;
      if(cur % 10 == 0) {
        while (cur % 10 == 0) {
          cur /= 10;
        }
        while (cur * 10 <= n) {
          ans.push_back(cur);
          cur *= 10;
        }
      }
      if (cur > n) {
        while(cur > n)cur /= 10;
        cur++;
      }
      if(cur % 10 == 0) {
        while (cur % 10 == 0) {
          cur /= 10;
        }
        while (cur * 10 <= n) {
          ans.push_back(cur);
          cur *= 10;
        }
      }
      ans.push_back(cur);
      while (cur * 10 <= n) {
        cur *= 10;
        ans.push_back(cur);
      }
    }
    return ans;
  }
};
