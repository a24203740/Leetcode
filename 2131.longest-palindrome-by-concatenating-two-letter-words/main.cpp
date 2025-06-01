#include "../includes.hpp"

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    array<array<int, 26>, 26> arr{{0}};
    for (const string &word : words) {
      arr[word[0] - 'a'][word[1] - 'a']++;
    }
    bool mid = false;
    int ans = 0;
    for(int i = 0; i < 26; i++) {
      for (int j = 0; j < i; j++) {
        ans += min(arr[i][j], arr[j][i]) * 4;
      }
      if(arr[i][i] > 0) {
        int tp = arr[i][i] / 2;
        ans += tp * 4;
        if(arr[i][i] % 2) {
          mid = true;
        }
      }
    }
    return mid ? ans + 2 : ans;
  }
};
