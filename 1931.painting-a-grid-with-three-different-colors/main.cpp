#include "../includes.hpp"

using state = bitset<15>;
class Solution {
public:
  void constructStates(int m, vector<state>& possibleStates) {
    possibleStates.clear();
    possibleStates.reserve(3*3*3*3*3);
    const state components[3] = {1, 2, 4};
    possibleStates.push_back(1);
    possibleStates.push_back(2);
    possibleStates.push_back(4);
    for(int i = 1; i < m; i++) {
      vector<state> newStates;
      newStates.reserve(possibleStates.size()*3);
      size_t offset = 3*i;
      size_t base = 3*(i-1);
      for(const auto& s : possibleStates) {
        for(int c = 0; c < 3; c++) {
          if((s & (components[c] << base)) == 0) {
            state newState = s | (components[c] << offset);
            newStates.push_back(newState);
          }
        }
      }
      possibleStates = std::move(newStates);
    }
  }
  void constructStateMatrix(const vector<state>& possibleStates, vector<vector<int>>& stateMatrix) {
    int n = possibleStates.size();
    stateMatrix.clear();
    stateMatrix.resize(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
      for(int j = 0; j < i; j++) {
        if(!(possibleStates[i] & possibleStates[j]).none()) continue;
        stateMatrix[i][j] = 1;
        stateMatrix[j][i] = 1;
      }
    }
  }
  void printState(const state& s, int m) {
    int prev = -1;
    for(int i = 0; i < m*3; i++) {
      if(s[i]) {
        if(i % 3 == 0) {
          cout << "R";
          if (prev == 0) cout << "error";
          prev = 0;
        } else if(i % 3 == 1) {
          cout << "G";
          if (prev == 1) cout << "error";
          prev = 1;
        } else {
          cout << "B";
          if (prev == 2) cout << "error";
          prev = 2;
        }
      }
    } 
  }
  int colorTheGrid(int m, int n) {
    const int mod = 1e9+7;
    int stateCount;
    vector<state> possibleStates;
    constructStates(m, possibleStates);
    stateCount = possibleStates.size();
    vector<vector<int>> stateMatrix;
    constructStateMatrix(possibleStates, stateMatrix);
    // for(const auto& s : possibleStates) {
    //   printState(s, m);
    //   cout << endl;
    // }
    array<vector<int>, 2> dp;
    dp[0].assign(stateCount, 1);
    int flag = 1;
    for(int i = 1; i < n; i++) {
      dp[flag].assign(stateCount, 0);
      for(int j = 0; j < stateCount; j++) {
        for(int k = 0; k < stateCount; k++) {
          if(stateMatrix[j][k] == 1) {
            dp[flag][k] = (dp[flag][k] + dp[!flag][j]) % mod;
          }
        }
      }
      flag = !flag;
    }
    flag = !flag;
    int ans = 0;
    for(int i = 0; i < stateCount; i++) {
      ans = (ans + dp[flag][i]) % mod;
    }
    return ans;
  }
};
