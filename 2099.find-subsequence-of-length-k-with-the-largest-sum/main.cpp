#include "../includes.hpp"

using pii = pair<int, int>;
class Solution {
public:
  vector<int> maxSubsequence(vector<int> &nums, int k) {
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;
    int n = nums.size();
    for(int i = 0; i < n; i++) {
      minHeap.emplace(nums[i], i);
      if(minHeap.size() > k) {
        minHeap.pop();
      }
    }
    vector<int> ans;
    while (!minHeap.empty()) {
      ans.push_back(minHeap.top().second);
      minHeap.pop();
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i++) {
      ans[i] = nums[ans[i]];
    }
    return ans;
  }
};
