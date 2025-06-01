#include "../includes.hpp"

using pii = pair<int, int>;
class Solution {
public:
  int closestMeetingNode(vector<int> &edges, int node1, int node2) {
    int n = edges.size();
    vector<pii> dis(n, {-1, -1});
    int disCount = 0;
    int it = node1;
    while(it != -1 && dis[it].first == -1) {
      dis[it].first = disCount++;
      it = edges[it];
    }
    disCount = 0;
    it = node2;
    int ansIndex = -1, andsDis = 1e9;
    while(it != -1 && dis[it].second == -1) {
      dis[it].second = disCount++;
      if(dis[it].first != -1) {
        int maximum = max(dis[it].first, dis[it].second);
        if(maximum < andsDis) {
          ansIndex = it;
          andsDis = maximum;
        }
        else if(maximum == andsDis && it < ansIndex) {
          ansIndex = it;
        }
      }
      it = edges[it];
    }
    return ansIndex;
  }
};
