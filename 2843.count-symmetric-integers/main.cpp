#include "../includes.hpp"

using vi = vector<int>;
using pii = pair<int, int>;
using vvi = vector<vi>;
using vpii = vector<pii>;
using vvpii = vector<vpii>;
class Solution {
public:
  int countSymmetricIntegers(int low, int high) {
    vvpii twodigits(20);
    vi candicates;
    for (int i = 0; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        twodigits[i + j].push_back({i, j});
      }
    }
    for(int i = 0; i < 10; i++) {
      candicates.push_back(i*11);
    }
    for (int i = 1; i < 10; i++) {
      for (int j = 0; j < 10; j++) {
        int pre = i * 1000 + j * 100;
        int sum = i + j;
        for (auto x : twodigits[sum]) {
          candicates.push_back(pre + x.first * 10 + x.second);
        }
      }
    }
    cout << candicates.size() << endl;
    sort(candicates.begin(), candicates.end());
    cout << "{";
    int count = 20;
    for(auto x : candicates) {
      cout << x << ",";
      count--;
      if (count == 0) {
        cout << endl;
        count = 20;
      }
    }
    cout << "}";
    int st = distance(candicates.begin(), lower_bound(candicates.begin(), candicates.end(), low));
    int ed = distance(candicates.begin(), upper_bound(candicates.begin(), candicates.end(), high + 1));
    return ed - st; // ed is not included, st is included
    
  }
};
