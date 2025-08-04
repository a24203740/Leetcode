#include "../includes.hpp"

class Solution {
public:
  int minimumDeletions(string word, int k) {
    array<int, 26> freq{};
    int n = word.size();
    for(auto c : word) {
      freq[c - 'a']++;
    }
    sort(freq.begin(), freq.end());
    auto requiredToMakeXSmallest = [&](int X) -> int {
      int ans = 0;
      int top = X + k;
      for(int i = 0; i < 26; i++) {
        if(freq[i] < X) ans += freq[i];
        else if(freq[i] > top) {
          ans += freq[i] - top;
        }
      }
      return ans;
    };
    int ans = 0;
    for(int i = 0; i < 26; i++) {
      ans = min(ans, requiredToMakeXSmallest(freq[i]));
    }
    return ans;
  }
};
