#include "../includes.hpp"

struct point {
  int x, y;
  point(): x(0), y(0) {}
  point(int x, int y) : x(x), y(y) {}
  bool operator<(const point &p) const {
    if (x != p.x)
      return x < p.x;
    return y > p.y;
  }
};
using contains = bitset<1024>;
using containsTable = array<contains, 1024>;
class Solution {
public:
  // return if p1 relatively upper left to p2
  bool isValidCorner(const point &p1, const point &p2) {
    return p1.x <= p2.x && p1.y >= p2.y;
  }
  int numberOfPairs(vector<vector<int>> &points) {
    vector<point> pointStruct;
    containsTable isTherePoint;
    containsTable regionHasPoint;
    map<int, int> xRanks, yRanks;
    for (const auto &p : points) {
      if (!xRanks.count(p[0])) {
        xRanks[p[0]] = 0;
      }
      if (!yRanks.count(p[1])) { 
        yRanks[p[1]] = 0;
      }
    }
    int X = 0, Y = 0;
    int rank = 0;
    for (auto &p : xRanks) {
      p.second = rank++;
    } 
    X = rank;
    rank = 0;
    for (auto &p : yRanks) {
      p.second = rank++;
    } 
    Y = rank;
    for (const auto &p : points) {
      int x = xRanks[p[0]], y = yRanks[p[1]];
      isTherePoint[x].set(y);
    }
    int N = points.size();
    pointStruct.reserve(N);
    for (int i = 0; i < N; i++) {
      pointStruct.emplace_back(xRanks[points[i][0]], yRanks[points[i][1]]);
    }
    sort(pointStruct.begin(), pointStruct.end());
    array<bitset<1024>, 1024> masks;
    masks[0].set(0);
    for(int y = 1; y < 1024; y++) {
      masks[y] = masks[y - 1];
      masks[y].set(y);
    }
    int ans = 0;
    int prevLeft = -1;
    for (int i = 0; i < N; i++) {
      point p1 = pointStruct[i];
      if (p1.x != prevLeft) {
        regionHasPoint[p1.x].reset();
        for(int x = p1.x + 1; x < X; x++) {
          regionHasPoint[x] = regionHasPoint[x - 1] | isTherePoint[x];
        }
        prevLeft = p1.x;
      }
      for (int j = 0; j < N; j++) {
        if (i == j) continue;
        point p2 = pointStruct[j];
        // cout << p1.x << " " << p1.y << " _ " << p2.x << " " << p2.y << endl;
        if (!isValidCorner(p1, p2)) {
          continue;
        }
        int left = p1.x, right = p2.x;
        int top = p1.y, bottom = p2.y;
        bitset<1024> mask = masks[top];
        if (bottom > 0) {
          mask ^= masks[bottom - 1];
        }
        // for(int i = 0; i < 10; i++) {
        //   cout << mask[i];
        // }
        // cout << endl;
        if (left == right) {
          contains leftedge = isTherePoint[left] & mask;
          if (leftedge.count() == 2) {
            // cout << "valid" << endl;
            ans++;
          }
          continue;
        }
        contains leftedge = isTherePoint[left] & mask;
        contains rightedge = isTherePoint[right] & mask;
        if (leftedge.count() == 1 && rightedge.count() == 1) {
          if (left < right - 1) {
            contains subreg = regionHasPoint[right - 1] & mask;
            if (subreg.count() > 0) {
              // cout << "invalid due to subregion has other points" << endl;
              continue;
            }
          }
          // cout << "valid" << endl;
          ans++;
        }
        continue;
      }
    }
    return ans; 
  }
};

