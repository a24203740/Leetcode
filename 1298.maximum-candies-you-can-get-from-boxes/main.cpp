#include "../includes.hpp"

#define MAXN 1001

class Solution {
public:
  int maxCandies(vector<int> &status, vector<int> &candies,
                 vector<vector<int>> &keys, vector<vector<int>> &containedBoxes,
                 vector<int> &initialBoxes) {
    bitset<MAXN> hasOpened{0}, hasBoxes{0};
    queue<int> bfs;
    int n = status.size();
    int ans = 0;
    for(int i = 0; i < n; i++) {
      hasOpened[i] = status[i] == 1;
    }
    for(auto &box : initialBoxes) {
      if(hasOpened[box]) {
        bfs.push(box);
      } else {
        hasBoxes.set(box);
      }
    }
    while(!bfs.empty()) {
      int next = bfs.front(); bfs.pop();
      ans += candies[next];
      for(auto &key : keys[next]) {
        hasOpened.set(key);
        if(hasBoxes[key]) {
          hasBoxes.reset(key);
          bfs.push(key);
        }
      }
      for(auto &box : containedBoxes[next]) {
        if(hasOpened[box]) {
          bfs.push(box);
        } else {
          hasBoxes.set(box);
        }
      }
    }
    return ans; 
  }
};
