#include "../includes.hpp"

struct efficient{
  double diff;
  int pass;
  int total;
  bool operator<(const efficient &other) const {
    return diff < other.diff;
  }
  efficient(int p, int t) : pass(p), total(t) {
    diff = (double)(pass + 1) / (total + 1) - (double)pass / total;
  }
};
class Solution {
public:
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    priority_queue<efficient> pq;
    double ans = 0;
    for(auto &c : classes){
      pq.emplace(c[0], c[1]);
      ans += (double)c[0] / c[1];
    }
    while(extraStudents--) {
      auto [d, p, t] = pq.top(); pq.pop();
      ans += d;
      pq.emplace(p + 1, t + 1);
    }
    return ans / classes.size();
  }
};
