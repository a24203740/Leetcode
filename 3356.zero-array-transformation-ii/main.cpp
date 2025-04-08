#include "../includes.hpp"

using pii = pair<int, int>;
class Solution {
public:
  vector<pii> prevResult;
  int prevK;
  bool canSatisfy(vector<int> &nums, vector<vector<int>> &queries, int k) {
    for(int i = prevK; i < k; i++){
      int start = queries[i][0], end = queries[i][1], val = queries[i][2];
      prevResult[start].first += val;
      prevResult[end].second += val;
    }
    int counter = 0;
    for (int x = 0; x < nums.size(); x++) {
      counter += prevResult[x].first;
      if(nums[x] > counter){
        prevK = k;
        return false;
      }
      counter -= prevResult[x].second;
    }
    for(int i = prevK; i < k; i++){
      int start = queries[i][0], end = queries[i][1], val = queries[i][2];
      prevResult[start].first -= val;
      prevResult[end].second -= val;
    }
    return true;
  }
  int minZeroArray(vector<int> &nums, vector<vector<int>> &queries) {
    prevK = 0;
    prevResult.assign(nums.size(), {0, 0});
    int l = 0, r = queries.size() + 1;
    while(l < r){
      int m = l + (r - l) / 2;
      if(canSatisfy(nums, queries, m)){
        r = m;
      }else{
        l = m + 1;
      }
    }
    if(l == queries.size() + 1) return -1;
    return l;
  }
};
