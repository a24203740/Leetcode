#include "../includes.hpp"
#include <queue>

class Solution {
public:
  int maxRemoval(vector<int> &nums, vector<vector<int>> &queries) {
    sort(queries.begin(), queries.end(), [](const auto &a, const auto &b) {
      return a[0] < b[0];
    });
    priority_queue<int> pq;
    int n = nums.size();
    int m = queries.size();
    vector<int> sub(n, 0);
    int counter = 0, walker = 0;
    int ans = m;
    for(int i = 0; i < n; i++) {
      if(nums[i] > counter) {
        while(walker < m && queries[walker][0] <= i) {
          pq.push(queries[walker][1]);
          walker++;
        }
        while(!pq.empty() && nums[i] > counter) {
          int rightBound = pq.top();
          pq.pop();
          if(rightBound >= i) {
            counter++;
            sub[rightBound]++;
            ans--;
          }
          else return -1;
        }
        if(nums[i] > counter) {
          return -1;
        }
      }
      counter -= sub[i];
    }
    return ans;
  }
};
