#include "../includes.hpp"

using ull = unsigned long long;
class Solution {
public:
  vector<ull> tenpow;
  vector<vector<ull>> palid;
  void genNDigitsPalid(int N) {
    palid[N].clear();
    if (N == 1) {
      for (int i = 0; i < 10; i++) {
        palid[N].push_back(i);
      }
      return;
    }
    if (N == 2) {
      for (int i = 0; i < 10; i++) {
        palid[N].push_back(i * 10 + i);
      }
      return;
    }
    int sz = 0;
    for (int count = 1; count < 10; count++) {
      int target = N - count * 2;
      if (target < 0) {
        break;
      }
      sz += palid[target].size();
    }
    palid[N].reserve(sz * 9);
    for (ull i = 1; i < 10; i++) {
      int st, count;
      if (N % 2 == 1)
        st = 1;
      else
        st = 2;
      count = (N - st) / 2;
      ull encap = tenpow[N - 1] * i + i;
      while (st < N) {
        for (auto x : palid[st]) {
          palid[N].push_back(encap + x * tenpow[count]);
        }
        st += 2;
        count--;
      }
    }
  }
  bool check(ull val, int k) {

    array<int, 70> digit{0};
    ull tp = 1;
    int d = 0;
    int MSB = 0;
    while (tp * k <= val) {
      tp *= k;
      d++;
    }
    MSB = d;
    while (val > 0) {
      if (val >= tp) {
        digit[d] = val / tp;
        val %= tp;
      }
      tp /= k;
      d--;
    }
    for (int i = 0; i <= MSB / 2; i++) {
      if (digit[i] != digit[MSB - i]) {
        return false;
      }
    }
    return true;
  }
  long long kMirror(int k, int n) {
    tenpow.resize(20);
    tenpow[0] = 1;
    for (int i = 1; i <= 18; i++) {
      tenpow[i] = tenpow[i - 1] * 10;
    }
    palid.resize(20);
    ull sum = 0;
    for (int i = 1; i <= 14; i++) {
      genNDigitsPalid(i);
      for (auto x : palid[i]) {
        if (x == 0)
          continue;
        if (check(x, k)) {
          n--;
          sum += x;
          if (n == 0) {
            return sum;
          }
        }
      }
    }
    return -1;
  }
};
