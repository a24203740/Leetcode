#include "../includes.hpp"

using ll = long long;
class Solution {
public:
  long long minimumDifference(vector<int> &nums) {
    priority_queue<ll> maxHeap;
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    ll minSum = 0;
    int n = nums.size() / 3;
    vector<ll> leftMin(n+1);
    for(int i = 0; i < n; i++) {
      minSum += nums[i];
      maxHeap.push(nums[i]);
    }
    int rb = 2*n;
    leftMin[0] = minSum;
    for(int i = n; i < rb; i++) {
      maxHeap.push(nums[i]);
      minSum += nums[i];
      minSum -= maxHeap.top();
      maxHeap.pop();
      leftMin[i-n+1] = minSum;
    }
    ll maxSum = 0;
    for(int i = rb; i < nums.size(); i++) {
      maxSum += nums[i];
      minHeap.push(nums[i]);
    }
    ll ans = leftMin[n] - maxSum;
    for(int i = rb-1; i >= n; i--) {
      minHeap.push(nums[i]);
      maxSum += nums[i];
      maxSum -= minHeap.top();
      minHeap.pop();
      ans = min(ans, leftMin[i-n] - maxSum);
    }
    return ans;
    
  }
};
