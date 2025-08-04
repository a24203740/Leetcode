#include "../includes.hpp"

class Solution {
public:
  int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k) {
    int lb = startPos - k, rb = startPos;
    int left = k, right = 0;
    int n = fruits.size();
    int half = n/2;
    int totalCount = 0;
    vector<int> pos, count;
    pos.reserve(n);
    count.reserve(n);
    for(auto &fruit : fruits) {
      pos.push_back(fruit[0]);
      count.push_back(fruit[1]);
    }
    auto lbit = lower_bound(pos.begin(), pos.end(), lb);
    auto rbit = lower_bound(pos.begin(), pos.end(), rb+1);
    int lp = lbit - pos.begin(), rp = rbit - pos.begin();
    for(int p = lp; p < rp; p++) {
      totalCount += count[p];
    }
    int ans = totalCount;
    auto calcK = [](int left, int right) {
      return max(left, right) + min(left, right) * 2;
    };
    while (left > 0) {
      do {
        cout << "walking left\n";
        if(lp < n && pos[lp] == lb) {
          cout << "give up " << count[lp] << " at " << pos[lp] << endl;
          totalCount -= count[lp];
          lp++;
        }
        lb++;
        left--;
        cout << left << " " << right << endl;
      }while (left > 0 && calcK(left, right) > k);
      while (right < k && calcK(left, right) < k) {
        cout << "walking right\n";
        rb++;
        right++;
        if(rp < n && pos[rp] <= rb) {
          cout << "grab " << count[rp] << " at " << pos[rp] << endl;
          totalCount += count[rp];
          rp++;
        }
        cout << left << " " << right << endl;
      }
      if(calcK(left, right) > k) {
        cout << "too far\n";
        continue;
      }
      cout << "totalCount: " << totalCount << endl;
      ans = max(ans, totalCount);
    }
    return ans;
  }
};
