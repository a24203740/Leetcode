#include "../includes.hpp"

class Solution {
public:
  bool canAssign(vector<int> &tasks, vector<int> &workers, int pills,
                 int strength, int onlyPrev) {
    deque<int> workerPool;
    int r = 0;
    int n = workers.size();
    for (int i = onlyPrev - 1; i >= 0; i--) {
      while (r < n) {
        if (workers[r] + strength >= tasks[i]) {
          workerPool.push_back(workers[r]);
          r++;
        } else {
          break;
        }
      }
      if (!workerPool.empty() && workerPool.front() >= tasks[i]) {
        workerPool.pop_front();
      } else if (pills > 0) {
        if (!workerPool.empty() && workerPool.back() + strength >= tasks[i]) {
          workerPool.pop_back();
          pills--;
        } else {
          return false;
        }
      } else {
        return false;
      }
    }
    return true;
  }
  int maxTaskAssign(vector<int> &tasks, vector<int> &workers, int pills,
                    int strength) {
    int n = tasks.size();
    int m = workers.size();
    int k = min(n, m);
    int l = 1, r = k;
    sort(tasks.begin(), tasks.end());
    sort(workers.begin(), workers.end(), [](int a, int b) { return a > b; });
    int ans = 0;
    while (l <= r) {
      // print [l, r]
      int mid = (l + r) / 2;
      if (canAssign(tasks, workers, pills, strength, mid)) {
        ans = mid;
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return ans;
  }
};
