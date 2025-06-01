#include "../includes.hpp"

class Solution {
public:
  const int mod = 1e9 + 7;
  int lengthAfterTransformations(string s, int t) {
    int ans = 0;
    array<array<int, 26>, 2> app;
    app[0].fill(0);
    app[1].fill(0);
    int round = 0;
    int n = s.size();
    int totalRound = t / 26;
    int left = t % 26;
    for (auto c : s) {
      int cur = c - 'a';
      cur += left;
      if (cur >= 26) {
        app[round][cur - 26]++;
        app[round][(cur - 25) % 26]++;
      } else {
        app[round][cur]++;
      }
    }
    round = 1;
    while (totalRound--) {
      int prev = !round;
      app[round][0] = (app[prev][0] + app[prev][25]) % mod;
      app[round][1] = (app[prev][1] + app[prev][0]) % mod;
      app[round][1] = (app[round][1] + app[prev][25]) % mod;
      for (int i = 2; i < 26; i++) {
        app[round][i] = (app[prev][i] + app[prev][i - 1]) % mod;
      }
      round = !round;
    }
    round = !round;
    for (int i = 0; i < 26; i++) {
      ans = (ans + app[round][i]) % mod;
    }
    return ans;
  }
};
