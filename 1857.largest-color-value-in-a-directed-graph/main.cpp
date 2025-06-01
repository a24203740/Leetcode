#include "../includes.hpp"

using colorCount = array<int, 26>;
int ans;
struct nodes {
  colorCount count{};
  vector<int> neighbor{};
  int inDegree{0};
  int color{0};
};
void saturized(const colorCount& a, colorCount& b) {
  for(int i = 0; i < 26; i++) {
    b[i] = max(a[i], b[i]);
    ans = max(ans, b[i]);
  }
}
class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    ans = 0;
    vector<nodes> graph(colors.size());
    vector<int> readySet; readySet.reserve(colors.size());
    int n = colors.size();
    for(const auto &edge : edges) {
      int u = edge[0], v = edge[1];
      graph[u].neighbor.push_back(v);
      graph[v].inDegree++;
    }
    for(int i = 0; i < n; i++) {
      graph[i].color = colors[i] - 'a';

      if(graph[i].inDegree == 0) {
        readySet.push_back(i);
      }
    }
    int it = 0;
    while(it < readySet.size()) {
      int id = readySet[it++];
      nodes &curNode = graph[id];
      curNode.count[curNode.color]++;
      ans = max(ans, curNode.count[curNode.color]);
      for(auto e : curNode.neighbor) {
        nodes &nextNode = graph[e];
        saturized(curNode.count, nextNode.count);
        nextNode.inDegree--;
        if(nextNode.inDegree == 0) {
          readySet.push_back(e);
        }
      }
    }
    if(readySet.size() < n) {
      return -1;
    }
    return ans; 
  }
};
