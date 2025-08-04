#include "../includes.hpp"

class Solution {
public:
  int matchPlayersAndTrainers(vector<int> &players, vector<int> &trainers) {
    int i = 0, j = 0;
    sort(players.begin(), players.end(), [](const int &a, const int &b) {
      return a < b;
    });
    sort(trainers.begin(), trainers.end(), [](const int &a, const int &b) {
      return a < b;
    });
    int n = players.size(), m = trainers.size();
    int ans = 0;
    while(i < n && j < m) {
      if(players[i] <= trainers[j]) {
        ans++;
        i++;
        j++;
      }
      else {
        i++;
      }
    }
    return ans;
  }
};
