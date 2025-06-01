#include "../includes.hpp"

class Solution {
public:
  vector<string> getLongestSubsequence(vector<string> &words,
                                       vector<int> &groups) {
    int prev = -1;
    int n = groups.size();
    vector<string> ans;
    for(int i = 0; i < n; i++) {
      if(groups[i] != prev) {
        ans.push_back(std::move(words[i]));
        prev = groups[i];
      }
    }
    return ans;
  }
};
