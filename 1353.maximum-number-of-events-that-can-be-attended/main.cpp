#include "../includes.hpp"

class Solution {
public:
  int maxEvents(vector<vector<int>> &events) {
    sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
      if (a[0] != b[0]) return a[0] < b[0];
      else return a[1] < b[1];
    });
    priority_queue<int, vector<int>, greater<int>> endTimes;
    int D = 1e5+1;
    int d = 0, e = 0, ans = 0;
    while (d < D) {
      if(endTimes.empty()) {
        if(e < events.size()) d = events[e][0];
        else break;
      }
      while(e < events.size() && events[e][0] <= d) {
        endTimes.push(events[e][1]);
        e++;
      }
      while(!endTimes.empty() && endTimes.top() < d) {
        endTimes.pop();
      }
      if(!endTimes.empty()) {
        endTimes.pop();
        ans++;
      }
      d++;
    }
    return ans;
  }
};
