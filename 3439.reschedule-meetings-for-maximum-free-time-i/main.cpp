#include "../includes.hpp"

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    int lastEndTime = 0;
    vector<int> gaps;
    int n = startTime.size();
    for (int i = 0; i < n; i++) {
      gaps.push_back(startTime[i] - lastEndTime);
      lastEndTime = endTime[i];
    }
    gaps.push_back(eventTime - lastEndTime);
    int window = 0;
    n = gaps.size();
    int lb = 0, rb = min(k, n - 1);
    for (int i = 0; i <= rb; i++) {
      window += gaps[i];
    }
    int ans = window;
    while(rb + 1 < n) {
      window -= gaps[lb++];
      window += gaps[++rb];
      ans = max(ans, window);
    }
    return ans;
  }
};
