#include "../includes.hpp"

class Solution {
public:
  long long minCost(vector<int> &basket1, vector<int> &basket2) {
    map<int, int> freq1, freq2, total;
    for (auto &fruit : basket1) {
      auto it = freq1.find(fruit);
      if (it == freq1.end()) {
        it = freq1.emplace(fruit, 0).first;
      }
      it->second++;
    }
    for (auto &fruit : basket2) {
      auto it = freq2.find(fruit);
      if (it == freq2.end()) {
        it = freq2.emplace(fruit, 0).first;
      }
      it->second++;
    }
    int minNum = 1e9+5;
    for (auto &p : freq1) {
      auto it = total.find(p.first);
      if (it == total.end()) {
        it = total.emplace(p.first, 0).first;
      }
      total[p.first] += p.second;
      if (freq2.find(p.first) == freq2.end()) {
        freq2.emplace(p.first, 0);
      }
    }
    for (auto &p : freq2) {
      auto it = total.find(p.first);
      if (it == total.end()) {
        it = total.emplace(p.first, 0).first;
      }
      total[p.first] += p.second;
      if (freq1.find(p.first) == freq1.end()) {
        freq1.emplace(p.first, 0);
      }
    }
    vector<pair<int, int>> to1, to2;
    for (auto &p : total) {
      minNum = min(minNum, p.first);  
      if (p.second % 2 != 0) {
        return -1; // Cannot balance if any fruit has an odd total count
      }
      int target = p.second / 2;
      int count1 = freq1[p.first];
      if(count1 < target) {
        to1.emplace_back(p.first, target - count1);
        // cout << p.first << " needs " << target - count1 << " to basket1" << endl;
      }
      else if (count1 > target) {
        to2.emplace_back(p.first, target - p.second + count1);
        // cout << p.first << " needs " << target - p.second + count1 << " to basket2" << endl;
      }
    }
    sort(to1.begin(), to1.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first < b.first;
    });
    sort(to2.begin(), to2.end(), [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.first > b.first;
    });
    long long int ans = 0;
    while (!to1.empty() && !to2.empty()) {
      auto &p1 = to1.back();
      auto &p2 = to2.back();
      long long minCount = min(p1.second, p2.second);
      long long int minCost = min(p1.first, p2.first);
      if(minCost > minNum * 2) {
        minCost = minNum * 2;
      }
      // cout << minCount << "\n";
      ans += minCount * minCost;
      // cout << minCount << " * " << min(p1.first, p2.first) << " = " << static_cast<long long>(minCount) * min(p1.first, p2.first) << endl;
      p1.second -= minCount;
      p2.second -= minCount;
      if (p1.second == 0) {
        to1.pop_back();
      }
      if (p2.second == 0) {
        to2.pop_back();
      }
    }
    return ans;
  }
};
